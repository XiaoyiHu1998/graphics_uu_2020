#include "Renderer.hpp"

Renderer::Renderer():
    window{sf::RenderWindow(sf::VideoMode(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y), "RayEngine")},
    rayCaster{RayCaster()}
    {}

void Renderer::init(){
    window.clear();
    for(uint8_t &color : drawColorArray_int){
        color = 0;
    }
    for(float  &color : drawColorArray_float){
        color = 0;
    }
    for(sf::Vector3i &color : renderColorArray_SDR){
        color = sf::Vector3i(0,0,0);
    }
    for(sf::Vector3f &color : renderColorArray_HDR){
        color = sf::Vector3f(0,0,0);
    }
}

void Renderer::renderFrame(){

    rayCaster.castRays(drawColorArray_float);

    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){
            RenderFrameBuffer.setPixel(x, y, sfColorFromFloatBuffer(x, y, drawColorArray_float));
        }
    }
}

void Renderer::drawFrame(){
    texture.loadFromImage(RenderFrameBuffer);
    sprite.setTexture(texture);
    window.draw(sprite);
}

sf::Color Renderer::sfColorFromFloatBuffer(uint x, uint y, const float* arrayPointer){

}