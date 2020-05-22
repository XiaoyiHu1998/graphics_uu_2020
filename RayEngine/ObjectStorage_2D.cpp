#include "ObjectStorage_2D.hpp"

ObjectStorage_2D::ObjectStorage_2D(){}

std::vector<Light_2D>& ObjectStorage_2D::getLightVector(){
    return lightVector;
}

std::vector<Object_2D>& ObjectStorage_2D::getobjects(){
    return objects;
}

void ObjectStorage_2D::init(){
    lightVector = {
            Light_2D(sf::Vector2f(200, 270), sf::Vector3f(1.0, 1.0, 0.7), 5),
            Light_2D(sf::Vector2f(250, 150), sf::Vector3f(0.8, 0.6, 0.8), 25),
            Light_2D(sf::Vector2f(100, 250), sf::Vector3f(0.1, 0.2, 0.1), 16),
            Light_2D(sf::Vector2f(600, 350), sf::Vector3f(0.2, 0.5, 0.4), 1)
    };

    objects = std::vector<Object_2D>{
            Circle_2D(sf::Vector2f(50,50),1)
        };
}