#include "Ray_2D.hpp"
#include "math.h"

Ray_2D::Ray_2D(){}

bool Ray_2D::intersects(GeometricObject_2D & object){
    return false;
}

void Ray_2D::setPosition(sf::Vector2i position){
    originPosition = sf::Vector2f(position.x, position.y);
}

void Ray_2D::setNormalizedDirection(sf::Vector2f lightPosition){
    sf::Vector2f direction = lightPosition - originPosition;
    // float directionLength = mathEngine::calculateLength(direction);
    // normalizedDirection = sf::Vector2f(direction.x / directionLength, direction.y / directionLength);
}

void Ray_2D::setDistanceToLight(sf::Vector2f lightPosition){
    sf::Vector2f originToLightVector = lightPosition - originPosition;
    // distanceToLight = mathEngine::calculateLength(originToLightVector);
}

float Ray_2D::getDistanceToLight(){
    return distanceToLight;
}


float Ray_2D::calculateLength(sf::Vector2f vector){
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}