#include "RayCaster_2D.hpp"

RayCaster_2D::RayCaster_2D()
{}

std::unique_ptr<float[]> RayCaster_2D::castRays(std::vector<Light_2D> & lightVector, std::vector<GeometricObject_2D> & geometricObjects){

    std::unique_ptr<float[]> heapBuffer = std::make_unique<float[]>(COLOR_BUFFER_SIZE);
    bool occluded = false;
    Ray_2D ray = Ray_2D();

    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){
            uint pixelIndex = (x + y * WINDOW_RESOLUTION_X) * 4;

            heapBuffer.get()[pixelIndex + 0] = 0;
            heapBuffer.get()[pixelIndex + 1] = 0;
            heapBuffer.get()[pixelIndex + 2] = 0;
            heapBuffer.get()[pixelIndex + 3] = 1;

            for(Light_2D & light : lightVector){
                sf::Vector2f lightPosition = light.getPosition();
                
                ray.setPosition(sf::Vector2i(x,y));
                ray.setNormalizedDirection(lightPosition);
                ray.setDistanceToLight(lightPosition);

                for(GeometricObject_2D & object : geometricObjects){
                    occluded = ray.intersects(object);
                }

                if(!occluded){
                    sf::Vector3f lightColorVec3 = light.getColor();
                    float attenuationValue = lightAttenuation(ray.getDistanceToLight());

                    heapBuffer.get()[pixelIndex + 0] += lightColorVec3.x * attenuationValue;
                    heapBuffer.get()[pixelIndex + 1] += lightColorVec3.y * attenuationValue;
                    heapBuffer.get()[pixelIndex + 2] += lightColorVec3.z * attenuationValue;
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
    return 1 / (distance); 
}