#include "RayEngine_2D.hpp"

RayEngine_2D::RayEngine_2D(sf::RenderWindow& window):
    // world{ObjectStorage_2D()},
    renderer{Renderer_2D(window)},
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