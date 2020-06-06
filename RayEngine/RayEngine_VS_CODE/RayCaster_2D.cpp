#include "RayCaster_2D.hpp"
#include "masterInclude.hpp"

RayCaster_2D::RayCaster_2D(unsigned int threadCount):
    threadCount{threadCount},
    keepRunning{true}
{
    std::cout << threadCount << std::endl;
}

void RayCaster_2D::castRays(std::vector<Light_2D> & lightVector, std::vector<std::shared_ptr<Circle_2D>> & objects, std::vector<float> & colorBuffer, int threadNumber, std::mutex& bufferMutex){
    uint_fast64_t rowsToRender = WINDOW_RESOLUTION_Y / threadCount;
    uint_fast64_t startRow = rowsToRender * threadNumber;
    uint_fast64_t endRow;
    
    if (threadNumber == THREADCOUNT - 1) {
        endRow = WINDOW_RESOLUTION_Y;
    }
    else {
        endRow = startRow + rowsToRender;
    }

    uint_fast64_t subBufferSize = (endRow - startRow) * WINDOW_RESOLUTION_X * 4;
    std::vector<float> subBuffer;
    subBuffer.clear();
    subBuffer.reserve(subBufferSize);
    for (int i = 0; i < subBufferSize; i++) {
        subBuffer.emplace_back(0.0f);
    }

    Ray_2D ray = Ray_2D();
    bool occluded = false;

    uint_fast64_t pixelIndex = 0;
    for(unsigned int y = startRow; y < endRow; y++){
        for(unsigned int x = 0; x < WINDOW_RESOLUTION_X; x++){
            subBuffer[pixelIndex + 0] = 0.0f;
            subBuffer[pixelIndex + 1] = 0.0f;
            subBuffer[pixelIndex + 2] = 0.0f;
            subBuffer[pixelIndex + 3] = 1.0f;

            for(Light_2D & light : lightVector){
                occluded = false;
                ray.setPosition(sf::Vector2i(x,y));
                ray.setNormalizedDirectionAndDistance(light.getPosition());

                for(std::shared_ptr<Circle_2D>& object : objects){
                    if(ray.intersects(object, light)){
                        occluded = true;
                        break;
                    }
                }

                if(!occluded){
                    sf::Vector3f lightColorVec3 = light.getColor();
                    float attenuationValue = lightAttenuation(ray.getDistanceToLight());
                    float intensity = light.getLightIntensity();

                    subBuffer[pixelIndex + 0] += lightColorVec3.x * attenuationValue * intensity;
                    subBuffer[pixelIndex + 1] += lightColorVec3.y * attenuationValue * intensity;
                    subBuffer[pixelIndex + 2] += lightColorVec3.z * attenuationValue * intensity;
                }
            }
            pixelIndex += 4;
        }
    }

    uint_fast64_t startIndex = startRow * WINDOW_RESOLUTION_X * 4;
    int number;
    std::lock_guard<std::mutex> lock(bufferMutex);
    for (int i = 0; i < subBuffer.size(); i++) {
        colorBuffer.at(startIndex + i) = subBuffer.at(i);
        number = i;
    }

}

void RayCaster_2D::castRaysMT(std::vector<Light_2D>& lightVector, std::vector<std::shared_ptr<Circle_2D>>& objects, std::vector<float>& colorBuffer, int threadNumber, std::vector<bool>& render, std::mutex& renderMutex, std::mutex& bufferMutex) {
    while (keepRunning)
    {
        renderMutex.lock();
        if (render[threadNumber]) {
            renderMutex.unlock();
            castRays(
                lightVector,
                objects,
                colorBuffer,
                threadNumber,
                bufferMutex
            );
            renderMutex.lock();
            render[threadNumber] = false;
            renderMutex.unlock();
        }
        else {
            renderMutex.unlock();
        }
    }
}

float RayCaster_2D::lightAttenuation(float distance){
    return 1 / (distance) * 5; 
}

void RayCaster_2D::exit(){
    keepRunning = false;
}