#include "RayCaster_2D.hpp"

RayCaster_2D::RayCaster_2D(unsigned int threadCount):
    threadCount{threadCount}
{
    std::cout << threadCount << std::endl;
}

void RayCaster_2D::castRays(std::vector<Light_2D> & lightVector, std::vector<std::shared_ptr<Circle_2D>> & objects, std::shared_ptr<float[]> colorBuffer, int threadNumber){
    uint_fast64_t rowsToRender = WINDOW_RESOLUTION_Y / threadCount;
    uint_fast64_t startRow = rowsToRender * threadNumber;
    uint_fast64_t endRow;
    
    if (threadNumber == threadCount - 1) {
        endRow = WINDOW_RESOLUTION_Y;
    }
    else {
        endRow = startRow + rowsToRender;
    }

    std::vector<float> tempBuffer;
    tempBuffer.reserve((endRow - startRow) * WINDOW_RESOLUTION_X * 4);

    Ray_2D ray = Ray_2D();
    bool occluded = false;

    uint_fast64_t pixelIndex = 0;
    for(unsigned int y = startRow; y < endRow; y++){
        for(unsigned int x = 0; x < WINDOW_RESOLUTION_X; x++){

            tempBuffer[pixelIndex + 0] = 0;
            tempBuffer[pixelIndex + 1] = 0;
            tempBuffer[pixelIndex + 2] = 0;
            tempBuffer[pixelIndex + 3] = 1;

            for(Light_2D & light : lightVector){
                occluded = false;
                ray.setPosition(sf::Vector2i(x,y));
                ray.setNormalizedDirectionAndDistance(light.getPosition());

                for(std::shared_ptr<Circle_2D> object : objects){
                    if(ray.intersects(object, light)){
                        occluded = true;
                        break;
                    }
                }

                if(!occluded){
                    sf::Vector3f lightColorVec3 = light.getColor();
                    float attenuationValue = lightAttenuation(ray.getDistanceToLight());
                    float intensity = light.getLightIntensity();

                    tempBuffer[pixelIndex + 0] += lightColorVec3.x * attenuationValue * intensity;
                    tempBuffer[pixelIndex + 1] += lightColorVec3.y * attenuationValue * intensity;
                    tempBuffer[pixelIndex + 2] += lightColorVec3.z * attenuationValue * intensity;
                    tempBuffer[pixelIndex + 3] = 1;
                }
            }
        }
        pixelIndex++;
    }

    colorBufferMutex.lock();
    uint_fast64_t startIndex = startRow * WINDOW_RESOLUTION_X * 4;
    for (int i = startIndex; i < endRow; i++) {
        colorBuffer.get()[i] = tempBuffer[i - startIndex];
    }
    colorBufferMutex.unlock();
}

float RayCaster_2D::lightAttenuation(float distance){
    return 1 / (distance) * 5; 
}
