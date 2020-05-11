#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "RayCaster.hpp"

class Renderer{
private:
    sf::RenderWindow window;
    RayCaster rayCaster;
    sf::Image RenderFrameBuffer;
    sf::Texture texture;
    sf::Sprite sprite;
    uint8_t drawColorArray_int[WINDOW_PIXEL_COUNT * 3];
    float drawColorArray_float[WINDOW_PIXEL_COUNT * 3];
    sf::Vector3f renderColorArray_HDR[WINDOW_PIXEL_COUNT];
    sf::Vector3i renderColorArray_SDR[WINDOW_PIXEL_COUNT];
public:
    Renderer();
    void init();
    void renderFrame();
    void drawFrame();
    sf::Color sfColorFromFloatBuffer(uint x, uint y, const float* arrayPointer);
};


#endif //RENDERER_HPP