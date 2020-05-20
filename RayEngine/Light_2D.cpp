#include "Light_2D.hpp"

Light_2D::Light_2D(const sf::Vector2f & position, const sf::Vector3f & lightColor):
    position{position},
    lightColor{lightColor}
    {};

const sf::Vector2f Light_2D::getPosition(){
    return position;
}

const sf::Vector3f Light_2D::getColor(){
    return lightColor;
}