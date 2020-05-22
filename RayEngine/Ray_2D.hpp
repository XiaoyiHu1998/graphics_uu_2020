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
public:
    Ray_2D();
    bool intersects(std::shared_ptr<Circle_2D> object);
    void setPosition(const sf::Vector2i & position);
    void setNormalizedDirection(const sf::Vector2f & lightPosition);
    void setDistanceToLight(const sf::Vector2f & lightPosition);
    float getDistanceToLight();
};

#endif //RAY_2D_HPP