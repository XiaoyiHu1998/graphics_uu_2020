#include "Ray_2D.hpp"
#include "math.h"

Ray_2D::Ray_2D():
    originPosition{sf::Vector2f()},
    normalizedDirection(sf::Vector2f()),
    distanceToLight{0}
{}

bool Ray_2D::intersects(std::shared_ptr<Circle_2D> object){

    double s = originPosition.x - object->getPosition().x;
    double t = originPosition.y - object->getPosition().y;
    double circleRadius = object->getRadius();

    double A = (normalizedDirection.x * normalizedDirection.x) + (normalizedDirection.y * normalizedDirection.y);
    double B = (2 * s * normalizedDirection.x) + (2 * t * normalizedDirection.y);
    double C = (s * s) + (t * t) - (circleRadius * circleRadius);

    double Discriminant = (B * B) - (4 * A * C);
    if(Discriminant < 0){
        return false;
    }
    else{
        return ((-1 * B + fastSqrt(Discriminant)) / 2 * A) >= 0 && ((-1 * B - fastSqrt(Discriminant)) / 2 * A) >= 0;
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
    return fastSqrt(vector.x * vector.x + vector.y * vector.y);
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