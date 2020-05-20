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
    sf::Vector2f getPosition(){return position;};
    float getSize();
    float getIntensity();
    sf::Vector3f getColor(){return lightColor;};
};
#endif //LIGHT_2D_HPP