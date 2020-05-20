#include "WorldEnviroment_2D.hpp"

WorldEnviroment_2D::WorldEnviroment_2D(){}

std::shared_ptr<std::vector<Light_2D>> WorldEnviroment_2D::getLightVector(){
    return std::make_shared<std::vector<Light_2D>>(lightVector);
}

std::shared_ptr<std::vector<GeometricObject_2D>> WorldEnviroment_2D::getGeometricObjects(){
    return std::make_shared<std::vector<GeometricObject_2D>>(geometricObjects);
}

void WorldEnviroment_2D::init(){
    lightVector = std::vector<Light_2D>{Light_2D()};
    geometricObjects = std::vector<GeometricObject_2D>{GeometricObject_2D()};
}

void WorldEnviroment_2D::import(){

}
