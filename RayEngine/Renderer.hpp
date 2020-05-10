#ifndef RENDERER
#define RENDERER

#include "RayCaster.hpp"

class Renderer{
private:
    sf::RenderWindow window;
    uint8_t colorArray[WINDOW_PIXEL_COUNT * 4];
    RayCaster raycaster;
public:
    Renderer();
    void init();
    void renderFrame();
    void drawFrame();
};


#endif //RENDERER