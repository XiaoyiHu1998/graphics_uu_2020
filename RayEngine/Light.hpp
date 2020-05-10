#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Object.hpp"

class Light : public Object{
private:
    float size;
    float intensity;
    sf::Vector3f position;
    Color lightColor;
public:
    Light();
    sf::Vector3f getPosition();
    float getSize();
    float getIntensity();
};
#endif //LIGHT_HPP