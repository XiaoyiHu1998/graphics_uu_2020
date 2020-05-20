#include "Renderer_2D.hpp"

Renderer_2D::Renderer_2D():
    window{sf::RenderWindow(sf::VideoMode(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y), "RayEngine")},
    rayCaster{RayCaster_2D()},
    objectStorage{ObjectStorage_2D()}
    {
        objectStorage.init();
    }

void Renderer_2D::init(){
    renderFrameBuffer = sf::Image();
    renderFrameBuffer.create(WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y);
    texture = sf::Texture();
    sprite = sf::Sprite();
    window.draw(sprite);
}

void Renderer_2D::renderFrame(){

    colorBuffer = rayCaster.castRays(objectStorage.getLightVector(), objectStorage.getGeometricObjects());
    
    for(uint y = 0; y < WINDOW_RESOLUTION_Y; y++){
        for(uint x = 0; x < WINDOW_RESOLUTION_X; x++){
            int currentCoord = x + y * WINDOW_RESOLUTION_X;
            sf::Color testColor = sf::Color(currentCoord % 255, currentCoord % 128, currentCoord & 64);
            renderFrameBuffer.setPixel(x, y, getRenderBufferColor(x, y));
        }
    }
}

void Renderer_2D::drawFrame(){
    window.clear(sf::Color::Black);
    texture.loadFromImage(renderFrameBuffer);
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(0,0));
    window.draw(sprite);
    window.display();
}

sf::Color Renderer_2D::getRenderBufferColor(int x, int y){
    int index = (x + y * WINDOW_RESOLUTION_X) * 4;

    sf::Uint8 r = static_cast<sf::Uint8>(colorBuffer[index + 0] * 255.0f);
    sf::Uint8 g = static_cast<sf::Uint8>(colorBuffer[index + 1] * 255.0f);
    sf::Uint8 b = static_cast<sf::Uint8>(colorBuffer[index + 2] * 255.0f);
    sf::Uint8 a = static_cast<sf::Uint8>(colorBuffer[index + 3] * 255.0f);

    return sf::Color(r,g,b,a);
}

sf::RenderWindow* Renderer_2D::getWindowPointer(){
    return &window;
}