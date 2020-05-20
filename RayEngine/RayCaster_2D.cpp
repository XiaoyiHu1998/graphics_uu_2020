#include "RayCaster_2D.hpp"

RayCaster_2D::RayCaster_2D(std::shared_ptr<std::vector<Light_2D>> lightVector, std::shared_ptr<std::vector<GeometricObject_2D>> geometricObjects)
{}

void RayCaster_2D::castRays(float (&colorBuffer)[WINDOW_PIXEL_COUNT * 4]){

    bool occluded = false;
    for(int y = 0; y < WINDOW_RESOLUTION_Y; y++){
        for(int x = 0; x < WINDOW_RESOLUTION_X; x++){
            float color[4] = {0, 0, 0, 1};

            for(Light_2D & light : *lightVector.get()){
                Ray_2D ray = Ray_2D();

                ray.setPosition(sf::Vector2i(x,y));
                ray.setNormalizedDirection(light.getPosition());
                ray.setDistanceToLight(light.getPosition());

                for(GeometricObject_2D & object : *geometricObjects.get()){
                    occluded = ray.intersects(object);
                }

                if(!occluded){
                    float lightColor[3] = {light.getColor().x, light.getColor().y, light.getColor().z};
                    float attenuationValue = lightAttenuation(ray.getDistanceToLight());
                    for(int i = 0; i < 3; i++){
                        color[i] = lightColor[i] * attenuationValue;
                    }
                }
            }

            int pixelIndex = x + y *WINDOW_RESOLUTION_X;
            for(int i = 0; i < 4; i++){
                colorBuffer[pixelIndex + i] = color[i];
            }
        }
    }
}

float RayCaster_2D::lightAttenuation(float distance){
    return 1 / (distance * distance); 
}