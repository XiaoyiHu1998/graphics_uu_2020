#include "RayEngine_2D.hpp"

RayEngine_2D::RayEngine_2D(sf::RenderWindow& window):
    renderer{window},
    drawFrame(true)
{}

void RayEngine_2D::init(int renderMode){
    renderer.init(renderMode);
}

void RayEngine_2D::handleInput(){

}

void RayEngine_2D::renderLoop(){
    if(drawFrame){
        renderer.renderFrame();
        renderer.drawFrame();
    }
}

void RayEngine_2D::exit(){
    renderer.exit();
}