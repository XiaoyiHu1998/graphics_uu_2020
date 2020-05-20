#ifndef LIGHT_2D_HPP
#define LIGHT_2D_HPP

#include "Object.hpp"

class Light_2D : public Object{
private:
    float size;
    float intensity;
    sf::Vector2f position;
    sf::Vector3f lightColor;
public:
    Light_2D(){};
    const sf::Vector2f getPosition(){return position;};
    const sf::Vector3f getColor(){return lightColor;};
    const float getSize();
    const float getIntensity();
};
#endif //LIGHT_2D_HPP