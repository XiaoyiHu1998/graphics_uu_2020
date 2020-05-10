#ifndef RENDERER
#define RENDERER

#include "RayCaster.hpp"

class Renderer{
private:
    sf::RenderWindow window;
    uint8_t drawColorArray[WINDOW_PIXEL_COUNT * 4];
    sf::Vector3f renderColorArray_HDR[WINDOW_PIXEL_COUNT];
    sf::Vector3i renderColorArray_SDR[WINDOW_PIXEL_COUNT];
    RayCaster raycaster;
public:
    Renderer();
    void init();
    void renderFrame();
    void drawFrame();
};


#endif //RENDERER