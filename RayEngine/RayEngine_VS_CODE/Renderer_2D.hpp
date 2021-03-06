#ifndef RENDERER_2D_HPP
#define RENDERER_2D_HPP

#include "RayCaster_2D.hpp"

class Renderer_2D{
private:
    RayCaster_2D rayCaster;
    ObjectStorage_2D objectStorage;

    sf::RenderWindow& window;
    sf::Image renderFrameBuffer;
    sf::Texture texture;
    sf::Sprite sprite;

    std::unique_ptr<float[]> colorBuffer;
    unsigned int threadCount;

    sf::Color getRenderBufferColor(int x, int y);
    float getBoundedfloat(float number);
public:
    Renderer_2D(sf::RenderWindow& window);
    void init();
    void renderFrame();
    void drawFrame();
};


#endif //RENDERER_2D_HPP