#include "RayEngine_2D.hpp"

RayEngine_2D::RayEngine_2D(sf::RenderWindow& window):
    renderer{window},
    drawFrame(true)
{}

void RayEngine_2D::init(){
    renderer.init();
}

void RayEngine_2D::handleInput(){

}

void RayEngine_2D::renderLoop(){
    if(drawFrame){
        renderer.renderFrame();
        renderer.drawFrame();
    }
}