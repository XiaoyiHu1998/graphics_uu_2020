#include "ObjectStorage_2D.hpp"

ObjectStorage_2D::ObjectStorage_2D(){}

std::shared_ptr<std::vector<Light_2D>> ObjectStorage_2D::getLightVector(){
    return std::make_shared<std::vector<Light_2D>>(lightVector);
}

std::shared_ptr<std::vector<GeometricObject_2D>> ObjectStorage_2D::getGeometricObjects(){
    return std::make_shared<std::vector<GeometricObject_2D>>(geometricObjects);
}

void ObjectStorage_2D::init(){
    lightVector = std::vector<Light_2D>{Light_2D()};
    geometricObjects = std::vector<GeometricObject_2D>{GeometricObject_2D()};
}

void ObjectStorage_2D::import(){

}
