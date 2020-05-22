#include "Ray_2D.hpp"
#include "math.h"

Ray_2D::Ray_2D():
    originPosition{sf::Vector2f()},
    normalizedDirection(sf::Vector2f()),
    distanceToLight{0}
{}

const bool Ray_2D::intersects(const Object_2D & object){
    return false;
}

const void Ray_2D::setPosition(const sf::Vector2i & position){
    originPosition = sf::Vector2f(position.x, position.y);
}

const void Ray_2D::setNormalizedDirection(const sf::Vector2f & lightPosition){
    sf::Vector2f direction = lightPosition - originPosition;
    float directionLength = calculateLength(direction);
    normalizedDirection = sf::Vector2f(direction.x / directionLength, direction.y / directionLength);
}

const void Ray_2D::setDistanceToLight(const sf::Vector2f & lightPosition){
    sf::Vector2f originToLightVector = lightPosition - originPosition;
    distanceToLight = calculateLength(originToLightVector);
}

float Ray_2D::getDistanceToLight(){
    return distanceToLight;
}


float Ray_2D::calculateLength(const sf::Vector2f & vector){
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}