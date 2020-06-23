#include "Ray_2D.hpp"
#include "math.h"

Ray_2D::Ray_2D():
    originPosition{sf::Vector2f()},
    normalizedDirection(sf::Vector2f()),
    distanceToLight{0}
{}

bool Ray_2D::intersects(std::shared_ptr<Circle_2D> object, Light_2D& light){
    objectPosition = object->getPosition();
    vectorToObject = objectPosition - originPosition;
    distanceToObject = calculateLength(vectorToObject);
    objectRadius = object->getRadius();

    if(distanceToObject <= objectRadius + 0.01 || calculateLength(objectPosition - light.getPosition()) < objectRadius){
        return true;
    }

    xDistance = originPosition.x - objectPosition.x;
    yDistance = originPosition.y - objectPosition.y;
    circleRadius = objectRadius;

    A = (normalizedDirection.x * normalizedDirection.x) + (normalizedDirection.y * normalizedDirection.y);
    B = (2 * xDistance * normalizedDirection.x) + (2 * yDistance * normalizedDirection.y);
    C = (xDistance * xDistance) + (yDistance * yDistance) - (circleRadius * circleRadius);

    Discriminant = (B * B) - (4 * A * C);
    if(Discriminant < 0){
        return false;
    }
    else{
        intersection1 = ((-1 * B + fastSqrt(Discriminant)) / 2 * A);
        intersection2 = ((-1 * B - fastSqrt(Discriminant)) / 2 * A);

        if(distanceToLight < intersection1 && distanceToLight < intersection2){
            return false;
        }
        return intersection2 > 0;
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