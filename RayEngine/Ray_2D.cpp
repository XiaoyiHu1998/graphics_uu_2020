#include "Ray_2D.hpp"
#include "math.h"

Ray_2D::Ray_2D():
    originPosition{sf::Vector2f()},
    normalizedDirection(sf::Vector2f()),
    distanceToLight{0}
{}

bool Ray_2D::intersects(std::shared_ptr<Circle_2D> object, Light_2D light){
    sf::Vector2f objectPosition = sf::Vector2f(object->getPosition().x, object->getPosition().y);
    sf::Vector2f vectorToObject = objectPosition - originPosition;
    // sf::Vector2f vectorToLight = light.getPosition() - originPosition;
    float distanceToObject = calculateLength(vectorToObject);
    float objectRadius = object->getRadius();

    if(distanceToObject <= objectRadius + 0.01 || calculateLength(objectPosition - light.getPosition()) < objectRadius){
        return true;
    }

    double xDistance = originPosition.x - objectPosition.x;
    double yDistance = originPosition.y - objectPosition.y;
    double circleRadius = objectRadius;

    double A = (normalizedDirection.x * normalizedDirection.x) + (normalizedDirection.y * normalizedDirection.y);
    double B = (2 * xDistance * normalizedDirection.x) + (2 * yDistance * normalizedDirection.y);
    double C = (xDistance * xDistance) + (yDistance * yDistance) - (circleRadius * circleRadius);

    double Discriminant = (B * B) - (4 * A * C);
    if(Discriminant < 0){
        return false;
    }
    else{
        float intersection1 = ((-1 * B + fastSqrt(Discriminant)) / 2 * A);
        float intersection2 = ((-1 * B - fastSqrt(Discriminant)) / 2 * A);

        // sf::Vector2f intersectionPoint1 = originPosition + intersection1 * normalizedDirection;
        // sf::Vector2f intersectionPoint2 = originPosition + intersection1 * normalizedDirection;

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