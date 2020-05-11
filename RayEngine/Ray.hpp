#ifndef RAY_HPP
#define RAY_HPP

#include "masterInclude.hpp"

class Ray{
private:
    sf::Vector3f originPosition;
    sf::Vector3f direction;
    float distanceToLight;
public:
    Ray();
    bool intersects(GeometricObject* object);
    void setPosition(sf::Vector3i originPosition);
    void setDirection(sf::Vector3f lightPosition);
    void setDistanceToLight(sf::Vector3f lightPosition);
    float getDistanceToLight();
};

#endif //RAY_HPP