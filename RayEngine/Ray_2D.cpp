#include "Ray_2D.hpp"
#include "math.h"

Ray_2D::Ray_2D():
    originPosition{sf::Vector2f()},
    normalizedDirection(sf::Vector2f()),
    distanceToLight{0}
{}

bool Ray_2D::intersects(Object_2D & object){
    int s = originPosition.x - object.getPosition().x;
    int t = originPosition.y - object.getPosition().y;
    int circleRadius = object.getRadius();

    int A = normalizedDirection.x * normalizedDirection.x + normalizedDirection.y + normalizedDirection.y;
    int B = 2 * s * normalizedDirection.x + 2 * t * normalizedDirection.y;
    int C = s * s + t * t - circleRadius* circleRadius;

    int Discriminant = B * B - 4 * A * C;
    return Discriminant >= 0;
}

void Ray_2D::setPosition(const sf::Vector2i & position){
    originPosition = sf::Vector2f(position.x, position.y);
}

void Ray_2D::setNormalizedDirection(const sf::Vector2f & lightPosition){
    sf::Vector2f direction = lightPosition - originPosition;
    float directionLength = calculateLength(direction);
    normalizedDirection = sf::Vector2f(direction.x / directionLength, direction.y / directionLength);
}

void Ray_2D::setDistanceToLight(const sf::Vector2f & lightPosition){
    sf::Vector2f originToLightVector = lightPosition - originPosition;
    distanceToLight = calculateLength(originToLightVector);
}

float Ray_2D::getDistanceToLight(){
    return distanceToLight;
}


float Ray_2D::calculateLength(const sf::Vector2f & vector){
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}