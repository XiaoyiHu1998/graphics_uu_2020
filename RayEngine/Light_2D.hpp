#ifndef LIGHT_2D_HPP
#define LIGHT_2D_HPP

#include "masterInclude.hpp"
#include <chrono>

class Light_2D{
private:
    sf::Vector2f origin;
    sf::Vector2f position;
    float spinRadius;
    sf::Vector3f lightColor;
public:
    Light_2D(const sf::Vector2f & position, const sf::Vector3f & lightColor);
    const sf::Vector2f getPosition();
    const sf::Vector3f getColor();
    void updatePosition();
    void updateColor();
};
#endif //LIGHT_2D_HPP