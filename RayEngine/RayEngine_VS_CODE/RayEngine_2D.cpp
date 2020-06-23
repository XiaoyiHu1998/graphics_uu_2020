#include "RayEngine_2D.hpp"

RayEngine_2D::RayEngine_2D(sf::RenderWindow& window):
    renderer{window}
{
    //timer = Timer();
}

void RayEngine_2D::init(int renderMode){
    renderer.init(renderMode);
}

void RayEngine_2D::handleInput(){

}

void RayEngine_2D::renderLoop(){
    renderer.renderFrame(timer);
    renderer.drawFrame(timer);
}

void RayEngine_2D::exit(){
    renderer.exitProgram();
}