#include "ObjectStorage_2D.hpp"

ObjectStorage_2D::ObjectStorage_2D(){}

std::vector<Light_2D> ObjectStorage_2D::getLightVector(){
    return lightVector;
}

std::vector<GeometricObject_2D> ObjectStorage_2D::getGeometricObjects(){
    return geometricObjects;
}

void ObjectStorage_2D::init(){
    lightVector = {
            Light_2D(sf::Vector2f(200, 270), sf::Vector3f(1, 1, 0.7)),
            Light_2D(sf::Vector2f(250, 150), sf::Vector3f(0.8, 0.6, 0.8)),
            Light_2D(sf::Vector2f(100, 250), sf::Vector3f(0.1, 20.2, 0.1)),
            Light_2D(sf::Vector2f(600, 350), sf::Vector3f(0.2, 0.5, 0.4))
    };

    geometricObjects = std::vector<GeometricObject_2D>{GeometricObject_2D()};
}