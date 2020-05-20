#include "RayEngine_2D.hpp"

RayEngine_2D::RayEngine_2D():
    world{ObjectStorage_2D()},
    renderer{Renderer_2D(world.getLightVector(), world.getGeometricObjects())},
    drawFrame(true)
{}

void RayEngine_2D::init(){
    world.init();
    renderer.init();
}

void RayEngine_2D::handleInput(){

}

void RayEngine_2D::renderLoop(){
    if(drawFrame){
        // renderer.renderFrame();
        renderer.drawFrame();
    }
}