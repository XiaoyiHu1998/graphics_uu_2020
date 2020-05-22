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
    sf::Vector2f lightPosition;

    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){
            uint pixelIndex = (x + y * WINDOW_RESOLUTION_X) * 4;

            heapBuffer.get()[pixelIndex + 0] = 0;
            heapBuffer.get()[pixelIndex + 1] = 0;
            heapBuffer.get()[pixelIndex + 2] = 0;
            heapBuffer.get()[pixelIndex + 3] = 1;

            for(Light_2D & light : lightVector){
                lightPosition = light.getPosition();
                
                ray.setPosition(sf::Vector2i(x,y));
                ray.setNormalizedDirectionAndDistance(lightPosition);

                for(std::shared_ptr<Circle_2D> object : objects){
                    occluded = ray.intersects(object); 
                    // float radius = object->getRadius();
                    // if(x < object->getPosition().x + radius && x > object->getPosition().x - radius){
                    //     if(y < object->getPosition().y + radius && y > object->getPosition().y - radius){
                    //         heapBuffer.get()[pixelIndex + 0] = 1.0f;
                    //         heapBuffer.get()[pixelIndex + 1] = 1.0f;
                    //         heapBuffer.get()[pixelIndex + 2] = 1.0f;
                    //         heapBuffer.get()[pixelIndex + 3] = 1.0f;
                    //     }
                    // }
                    if(occluded){
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
    
    for(Light_2D &light : lightVector){
        for(int i = 0 ; i < 1000; i++){
            light.updatePosition();
            light.updateColor();
        }
    } 

    return heapBuffer;
}

float RayCaster_2D::lightAttenuation(float distance){
    return 1 / (distance) * 2; 
}
