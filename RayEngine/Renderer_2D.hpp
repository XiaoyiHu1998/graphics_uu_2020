#ifndef RENDERER_2D_HPP
#define RENDERER_2D_HPP

#include "RayCaster_2D.hpp"

class Renderer_2D{
private:
    RayCaster_2D rayCaster;

    sf::RenderWindow window;
    sf::Image renderFrameBuffer;
    sf::Texture texture;
    sf::Sprite sprite;
    float colorBuffer[WINDOW_PIXEL_COUNT * 4];
    sf::Color fillRenderBuffer(int pixelIndex);
public:
    Renderer_2D(std::shared_ptr<std::vector<Light_2D>> lightVector, std::shared_ptr<std::vector<GeometricObject_2D>> geometricObjects);
    void init();
    void renderFrame();
    void drawFrame();
};


#endif //RENDERER_2D_HPP