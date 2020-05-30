#ifndef RAY_2D_HPP
#define RAY_2D_HPP

#include "masterInclude.hpp"
#include "ObjectStorage_2D.hpp"

class Ray_2D{
private:
    sf::Vector2f originPosition;
    sf::Vector2f normalizedDirection;
    float distanceToLight;

    float calculateLength(const sf::Vector2f & vector);
    float fastSqrt(float number);

    float objectRadius;
    float distanceToObject;
    sf::Vector2f objectPosition;
    sf::Vector2f vectorToObject;
    double xDistance;
    double yDistance;
    double circleRadius;
    double A;
    double B;
    double C;
    double Discriminant;
    float intersection1;
    float intersection2;
public:
    Ray_2D();
    bool intersects(std::shared_ptr<Circle_2D> object, Light_2D& light);
    void setPosition(const sf::Vector2i & position);
    void setNormalizedDirectionAndDistance(const sf::Vector2f & lightPosition);
    float getDistanceToLight();
};

#endif //RAY_2D_HPP