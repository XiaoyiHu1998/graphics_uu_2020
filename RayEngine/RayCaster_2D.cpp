#include "RayCaster_2D.hpp"

RayCaster_2D::RayCaster_2D(sf::Vector2f cameraOrigin, float screenDistance, WorldEnviroment_2D* worldPointer):
    cameraOrigin{cameraOrigin},
    screenDistance{screenDistance},
    worldPointer{worldPointer}
{}

void RayCaster_2D::castPrimaryRay(){

}

void RayCaster_2D::castShadowRay(){

}

void RayCaster_2D::castRays(float* floatArrayPointer){
    std::shared_ptr<std::vector<Light_2D>> lightArray = worldPointer->getLightVector();
    std::shared_ptr<std::vector<GeometricObject_2D>> objects = worldPointer->getGeometricObjects();

    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){
            sf::Vector3f pixelColor = sf::Vector3f(0,0,0);
            for(Light_2D & light : *lightArray){
                Ray_2D ray = Ray_2D();
                ray.setPosition(sf::Vector2i(x,y));
                ray.setNormalizedDirection(light.getPosition());
                ray.setDistanceToLight(light.getPosition());

                bool occluded = false;
                for(GeometricObject_2D object : *objects){
                    if(ray.intersects(&object)){
                        occluded = true;
                        break;
                    }
                }

                if(!occluded){
                    pixelColor += light.getColor() * lightAttenuation(ray.getDistanceToLight());
                }
                
                *floatArrayPointer = pixelColor.x;
                floatArrayPointer++;
                *floatArrayPointer = pixelColor.y;
                floatArrayPointer++;
                *floatArrayPointer = pixelColor.z;
                floatArrayPointer++;
            }
        }
    }
}


float RayCaster_2D::lightAttenuation(float distance){
    return 0;
}