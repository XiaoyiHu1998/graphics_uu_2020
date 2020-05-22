#include "Light_2D.hpp"
#include "math.h"
#include <chrono>

Light_2D::Light_2D(const sf::Vector2f & position, const sf::Vector3f & lightColor, float lightIntensity):
    position{position},
    lightColor{lightColor},
    lightIntensity{lightIntensity}
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
    
    if(position.x < 100){
        position.x = 600;
    }
    else{
        position.x -= 1;
    }

}

void Light_2D::updateColor(){
    if(lightColor.z > 1){
        lightColor.x = 0;
    }
    else{
        lightColor.x += 0.1;
    }

    if(lightColor.y > 1){
        lightColor.y = 0;
    }
    else{
        lightColor.y += 0.2;
    }


    if(lightColor.z > 1){
        lightColor.z = 0;
    }
    else{
        lightColor.z += 0.05;
    }
}