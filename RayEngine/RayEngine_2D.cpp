#include "RayEngine_2D.hpp"

RayEngine_2D::RayEngine_2D():
    world{ObjectStorage_2D()},
    renderer{Renderer_2D(world.getLightVector(), world.getGeometricObjects())}
{}

void RayEngine_2D::init(){

}

void RayEngine_2D::handleInput(){

}

void RayEngine_2D::renderLoop(){
    // renderer.renderFrame();
    // renderer.drawFrame();
}