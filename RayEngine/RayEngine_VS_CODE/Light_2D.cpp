#include "Light_2D.hpp"
#include "math.h"
#include <chrono>

Light_2D::Light_2D(const sf::Vector2f& position, const sf::Vector3f& lightColor, float intensity, bool dynamic):
    position{position},
    lightColor{lightColor},
    lightIntensity{intensity},
    dynamic{dynamic}
{};

const sf::Vector2f Light_2D::getPosition(){
    return position;
}

const sf::Vector3f Light_2D::getColor(){
    return lightColor;
}

float Light_2D::getLightIntensity(){
    return lightIntensity;
}

void Light_2D::updatePosition(){
    if (!dynamic) {
        return;
    }
    
    if(position.x > WINDOW_RESOLUTION_X + 75){
        position.x = -100;
    }
    else{
        position.x += 5;;
        if(position.x > 10){
            position.x += position.x / 25;
        }
    }

}

void Light_2D::updateColor(){
    if(lightColor.x > 1){
        lightColor.x = 0.6;
    }
    else{
        lightColor.x += 0.0003;
    }

    if(lightColor.y > 1){
        lightColor.y = 0.5;
    }
    else{
        lightColor.y += 0.007;
    }


    if(lightColor.z > 1){
        lightColor.z = 0.8;
    }
    else{
        lightColor.z += 0.003;
    }
}