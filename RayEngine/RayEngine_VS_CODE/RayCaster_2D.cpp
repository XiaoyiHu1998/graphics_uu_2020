#include "RayCaster_2D.hpp"

RayCaster_2D::RayCaster_2D(unsigned int threadCount):
    threadCount{threadCount}
{
    std::cout << threadCount << std::endl;
}

std::unique_ptr<float[]> RayCaster_2D::castRays(std::vector<Light_2D> & lightVector, std::vector<std::shared_ptr<Circle_2D>> & objects){

    std::unique_ptr<float[]> heapBuffer = std::make_unique<float[]>(COLOR_BUFFER_SIZE);
    Ray_2D ray = Ray_2D();
    bool occluded = false;

    for(unsigned int y = 0; y < WINDOW_RESOLUTION_Y; y++){
        
        for(unsigned int x = 0; x < WINDOW_RESOLUTION_X; x++){
            unsigned int pixelIndex = (x + y * WINDOW_RESOLUTION_X) * 4;

            heapBuffer.get()[pixelIndex + 0] = 0;
            heapBuffer.get()[pixelIndex + 1] = 0;
            heapBuffer.get()[pixelIndex + 2] = 0;
            heapBuffer.get()[pixelIndex + 3] = 1;

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

                    heapBuffer.get()[pixelIndex + 0] += lightColorVec3.x * attenuationValue * intensity;
                    heapBuffer.get()[pixelIndex + 1] += lightColorVec3.y * attenuationValue * intensity;
                    heapBuffer.get()[pixelIndex + 2] += lightColorVec3.z * attenuationValue * intensity;
                    heapBuffer.get()[pixelIndex + 3] = 1;
                }
            }
        }
    }

    return heapBuffer;
}

float RayCaster_2D::lightAttenuation(float distance){
    return 1 / (distance * distance) * 150; 
}
