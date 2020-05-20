#ifndef RENDERER_2D_HPP
#define RENDERER_2D_HPP

#include "RayCaster_2D.hpp"

class Renderer_2D{
private:
    sf::RenderWindow window;
    RayCaster_2D rayCaster;
    sf::Image RenderFrameBuffer;
    sf::Texture texture;
    sf::Sprite sprite;
    uint8_t drawColorArray_int[WINDOW_PIXEL_COUNT * 3];
    float drawColorArray_float[WINDOW_PIXEL_COUNT * 3];
    sf::Vector3f renderColorArray_HDR[WINDOW_PIXEL_COUNT];
    sf::Vector3i renderColorArray_SDR[WINDOW_PIXEL_COUNT];
public:
    Renderer_2D(std::shared_ptr<WorldEnviroment_2D> worldPointer);
    void init();
    void renderFrame();
    void drawFrame();
    sf::Color sfColorFromFloatBuffer(uint x, uint y, const float* arrayPointer);
};


#endif //RENDERER_2D_HPP