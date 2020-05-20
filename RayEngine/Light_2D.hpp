#ifndef LIGHT_2D_HPP
#define LIGHT_2D_HPP

#include "Object.hpp"

class Light_2D{
private:
    sf::Vector2f position;
    sf::Vector3f lightColor;
public:
    Light_2D(const sf::Vector2f & position, const sf::Vector3f & color);
    const sf::Vector2f getPosition();
    const sf::Vector3f getColor();
};
#endif //LIGHT_2D_HPP