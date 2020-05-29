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

    std::vector<float> colorBuffer;
    std::vector<std::thread> renderThreads;
    std::vector<bool> render;
    unsigned int threadCount;
    std::mutex renderMutex;
    std::mutex finishMutex;
    std::mutex bufferMutex;
    int renderMode;

    sf::Color getRenderBufferColor(uint_fast64_t x, uint_fast64_t y);
    float getBoundedfloat(float number);
public:
    Renderer_2D(sf::RenderWindow& window);
    void init(int mode);
    void renderFrame();
    void drawFrame();
    void exit();
};


#endif //RENDERER_2D_HPP