#include "Renderer_2D.hpp"

Renderer_2D::Renderer_2D(ObjectStorage_2D* worldPointer):
    window{sf::RenderWindow(sf::VideoMode(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y), "RayEngine")},
    rayCaster{RayCaster_2D(sf::Vector2f(0,0), 2, worldPointer)}
    {}

void Renderer_2D::init(){
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

    renderFrameBuffer = sf::Image();
    texture = sf::Texture();
    sprite = sf::Sprite();
}

void Renderer_2D::renderFrame(){

    rayCaster.castRays(drawColorArray_float);

    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){
            renderFrameBuffer.setPixel(x, y, sfColorFromFloatBuffer(x, y, drawColorArray_float));
        }
    }
}

void Renderer_2D::drawFrame(){
    texture.loadFromImage(renderFrameBuffer);
    sprite.setTexture(texture);
    window.draw(sprite);
}

sf::Color Renderer_2D::sfColorFromFloatBuffer(uint x, uint y, const float* arrayPointer){
    return sf::Color();
}
