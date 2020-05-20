#ifndef RAY_HPP
#define RAY_HPP

#include "masterInclude.hpp"
#include "2D/WorldEnviroment_2D.hpp"

class Ray_2D{
private:
    sf::Vector3f originPosition;
    sf::Vector3f direction;
    float distanceToLight;
public:
    Ray_2D();
    bool intersects(GeometricObject_2D* object);
    void setPosition(sf::Vector3i originPosition);
    void setDirection(sf::Vector3f lightPosition);
    void setDistanceToLight(sf::Vector3f lightPosition);
    float getDistanceToLight();
};

#endif //RAY_HPP