#ifndef LIGHT_2D_HPP
#define LIGHT_2D_HPP

#include "masterInclude.hpp"
#include <chrono>

class Light_2D{
private:
    sf::Vector2f position;
    sf::Vector3f lightColor;
    float lightIntensity;
    bool dynamic;
public:
    Light_2D(const sf::Vector2f & position, const sf::Vector3f & lightColor, float intensity, bool dynamic = true);
    const sf::Vector2f getPosition();
    const sf::Vector3f getColor();
    float getLightIntensity();
    void updatePosition();
    void updateColor();
};
#endif //LIGHT_2D_HPP