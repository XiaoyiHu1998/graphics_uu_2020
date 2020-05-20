#include "RayEngine_2D.hpp"

RayEngine_2D::RayEngine_2D():
    // world{ObjectStorage_2D()},
    renderer{Renderer_2D()},
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

sf::RenderWindow* RayEngine_2D::getWindowPointer(){
    renderer.getWindowPointer();
}