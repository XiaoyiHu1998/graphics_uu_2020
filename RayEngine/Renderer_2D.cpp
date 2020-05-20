#include "Renderer_2D.hpp"

Renderer_2D::Renderer_2D(std::shared_ptr<std::vector<Light_2D>> lightVector, std::shared_ptr<std::vector<GeometricObject_2D>> geometricObjects):
    window{sf::RenderWindow(sf::VideoMode(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y), "RayEngine")},
    rayCaster{RayCaster_2D(lightVector, geometricObjects)}
    {}

void Renderer_2D::init(){
    renderFrameBuffer = sf::Image();
    texture = sf::Texture();
    sprite = sf::Sprite();
    window.draw(sprite);
}

void Renderer_2D::renderFrame(){

    rayCaster.castRays(colorBuffer);

    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){
            renderFrameBuffer.setPixel(x, y, fillRenderBuffer(x + y * WINDOW_RESOLUTION_X));
        }
    }
}

void Renderer_2D::drawFrame(){
    texture.loadFromImage(renderFrameBuffer);
    sprite.setTexture(texture);
    window.draw(sprite);
}

sf::Color Renderer_2D::fillRenderBuffer(int pixelIndex){
    int index = pixelIndex * 4;
    return sf::Color(colorBuffer[index], colorBuffer[index+1], colorBuffer[index+2], colorBuffer[index+3]);
}
