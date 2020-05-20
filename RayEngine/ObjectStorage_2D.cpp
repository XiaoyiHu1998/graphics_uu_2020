#include "ObjectStorage_2D.hpp"

ObjectStorage_2D::ObjectStorage_2D(){}

std::vector<Light_2D> ObjectStorage_2D::getLightVector(){
    return lightVector;
}

std::vector<GeometricObject_2D> ObjectStorage_2D::getGeometricObjects(){
    return geometricObjects;
}

void ObjectStorage_2D::init(){
    lightVector.push_back(
        Light_2D(sf::Vector2f(300, 250), sf::Vector3f(0.4, 0.1, 0.7))
        );
    geometricObjects = std::vector<GeometricObject_2D>{GeometricObject_2D()};
}