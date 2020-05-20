#ifndef LIGHT_2D_HPP
#define LIGHT_2D_HPP

#include "Object.hpp"

class Light_2D : public Object{
private:
    float size;
    float intensity;
    sf::Vector2f position;
    Color lightColor;
public:
    Light_2D();
    sf::Vector2f getPosition();
    float getSize();
    float getIntensity();
    sf::Vector2f getColor();
};
#endif //LIGHT_2D_HPP