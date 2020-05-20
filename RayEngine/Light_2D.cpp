#include "Light_2D.hpp"
#include "math.h"
#include <chrono>

Light_2D::Light_2D(const sf::Vector2f & position, const sf::Vector3f & lightColor):
    position{position},
    lightColor{lightColor},
    spinRadius{10}
    {};

const sf::Vector2f Light_2D::getPosition(){
    return position;
}

const sf::Vector3f Light_2D::getColor(){
    return lightColor;
}

void Light_2D::updatePosition(){
    
    if(position.x < WINDOW_RESOLUTION_X / 5){
        position.x += 200;
    }
    else{
        position.x -= 5;
    }
}