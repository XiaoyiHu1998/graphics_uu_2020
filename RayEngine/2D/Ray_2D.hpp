#ifndef RAY_2D_HPP
#define RAY_2D_HPP

#include "masterInclude.hpp"
#include "2D/WorldEnviroment_2D.hpp"

class Ray_2D{
private:
    sf::Vector2f originPosition;
    sf::Vector2f direction;
    float distanceToLight;
public:
    Ray_2D();
    bool intersects(GeometricObject_2D* object);
    void setPosition(sf::Vector2i originPosition);
    void setDirection(sf::Vector2f lightPosition);
    void setDistanceToLight(sf::Vector2f lightPosition);
    float getDistanceToLight();
};

#endif //RAY_2D_HPP