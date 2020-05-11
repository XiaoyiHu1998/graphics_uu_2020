#include "RayCaster.hpp"

RayCaster::RayCaster(sf::Vector3f cameraOrigin, float screenDistance, std::shared_ptr<WorldEnviroment> worldPointer):
    cameraOrigin{cameraOrigin},
    screenDistance{screenDistance},
    worldPointer{worldPointer}
{}

void RayCaster::castPrimaryRay(){

}

void RayCaster::castShadowRay(){

}

void RayCaster::castRays(float* floatArrayPointer){
    std::shared_ptr<std::vector<Light>> lightArray = worldPointer->getLightVector();
    std::shared_ptr<std::vector<GeometricObject>> objects = worldPointer->getGeometricObjects();

    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){
            sf::Vector3f pixelColor = sf::Vector3f(0,0,0);
            for(Light & light : *lightArray){
                Ray ray = Ray();
                ray.setPosition(sf::Vector3i(x,y,0));
                ray.setDirection(light.getPosition());
                ray.setDistanceToLight(light.getPosition());

                bool occluded = false;
                for(GeometricObject object : *objects){
                    if(ray.intersects(&object)){
                        occluded = true;
                        break;
                    }
                }

                if(!occluded){
                    pixelColor += light.getColor() * mathEngine::lightAttenuation(ray.getDistanceToLight());
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