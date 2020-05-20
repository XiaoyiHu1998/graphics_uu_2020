#include "RayCaster_2D.hpp"

RayCaster_2D::RayCaster_2D()
{}

std::unique_ptr<float[]> RayCaster_2D::castRays(std::vector<Light_2D> lightVector, std::vector<GeometricObject_2D> geometricObjects){

    std::unique_ptr<float[]> heapBuffer = std::make_unique<float[]>(COLOR_BUFFER_SIZE);
    bool occluded = false;
    Ray_2D ray = Ray_2D();
    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){

            for(Light_2D & light : lightVector){
                sf::Vector2f lightPosition = light.getPosition();
                ray.setPosition(sf::Vector2i(x,y));
                ray.setNormalizedDirection(lightPosition);
                ray.setDistanceToLight(lightPosition);

                for(GeometricObject_2D & object : geometricObjects){
                    occluded = ray.intersects(object);
                }

                if(!occluded){
                    sf::Vector3f lightColorVec3 = sf::Vector3f(0,0,0);
                    lightColorVec3 = light.getColor();
                    uint pixelIndex = (x + y * WINDOW_RESOLUTION_X) * 4;

                    float attenuationValue = lightAttenuation(ray.getDistanceToLight());
                    heapBuffer.get()[pixelIndex + 0] = lightColorVec3.x * attenuationValue;
                    heapBuffer.get()[pixelIndex + 1] = lightColorVec3.y * attenuationValue;
                    heapBuffer.get()[pixelIndex + 2] = lightColorVec3.z * attenuationValue;
                    heapBuffer.get()[pixelIndex + 3] = 1;
                }
            }
        }
    }
    
    for(int i = 0; i < COLOR_BUFFER_SIZE; i++){
        std::cout << "index: " << i << " - float: " << heapBuffer.get()[i] << std::endl;
    } 

    return heapBuffer;
}

float RayCaster_2D::lightAttenuation(float distance){
    return 1 / (distance * distance); 
}