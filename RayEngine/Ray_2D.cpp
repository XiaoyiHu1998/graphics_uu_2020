#include "Ray_2D.hpp"
#include "math.h"

Ray_2D::Ray_2D():
    originPosition{sf::Vector2f()},
    normalizedDirection(sf::Vector2f()),
    distanceToLight{0}
{}

bool Ray_2D::intersects(std::shared_ptr<Circle_2D> object){
    // int adjustedOriginX = originPosition.x + normalizedDirection.x * 0.001;
    // int adjustedOriginY = originPosition.y + normalizedDirection.y * 0.001;

    // int adjustedEndX = object->getPosition().x - normalizedDirection.x * 0.001;
    // int adjustedEndY = object->getPosition().x - normalizedDirection.y * 0.001;

    float s = originPosition.x - object->getPosition().x;
    float t = originPosition.y - object->getPosition().y;
    float circleRadius = object->getRadius();

    float A = (normalizedDirection.x * normalizedDirection.x) + (normalizedDirection.y * normalizedDirection.y);
    float B = (2 * s * normalizedDirection.x) + (2 * t * normalizedDirection.y);
    float C = (s * s) + (t * t) - (circleRadius * circleRadius);

    float Discriminant = (B * B) - (4 * A * C);
    if(Discriminant < 0){
        return false;
    }
    else{
        bool firstResult = ((-1 * B + fastSqrt(Discriminant)) / 2 * A) <= distanceToLight;
        bool secondResult = ((-1 * B - fastSqrt(Discriminant)) / 2 * A) <= distanceToLight;
        return firstResult || secondResult;
    }
}

void Ray_2D::setPosition(const sf::Vector2i & position){
    originPosition = sf::Vector2f(position.x, position.y);
}

void Ray_2D::setNormalizedDirectionAndDistance(const sf::Vector2f & lightPosition){
    sf::Vector2f direction = lightPosition - originPosition;
    distanceToLight = calculateLength(direction);
    normalizedDirection = sf::Vector2f(direction.x / distanceToLight, direction.y / distanceToLight);
}

float Ray_2D::getDistanceToLight(){
    return distanceToLight;
}


float Ray_2D::calculateLength(const sf::Vector2f & vector){
    // std::cout << fastSqrt(vector.x * vector.x + vector.y * vector.y) << "," << sqrt(vector.x * vector.x + vector.y * vector.y) << std::endl;
    // return fastSqrt(vector.x * vector.x + vector.y * vector.y);
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}


float Ray_2D::fastSqrt(float number){
    const float threehalfs = 1.5f;

    float x2 = number * 0.5f;
    float y  = number;
    long i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );
    y  = y * ( threehalfs - ( x2 * y * y ) );

	return 1 / y;
}