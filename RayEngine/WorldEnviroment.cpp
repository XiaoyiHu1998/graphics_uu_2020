#include "WorldEnviroment.hpp"

WorldEnviroment::WorldEnviroment(){}

std::shared_ptr<std::vector<Light>> WorldEnviroment::getLightVector(){
    return std::make_shared<std::vector<Light>>(lightVector);
}

std::shared_ptr<std::vector<GeometricObject>> WorldEnviroment::getGeometricObjects(){
    return std::make_shared<std::vector<GeometricObject>>(geometricObjects);
}

void WorldEnviroment::init(){
    lightVector = std::vector<Light>{Light()};
    geometricObjects = std::vector<GeometricObject>{GeometricObject()};
}

void WorldEnviroment::import(){

}
