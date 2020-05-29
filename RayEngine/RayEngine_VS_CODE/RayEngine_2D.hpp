#ifndef RAY_ENGINE_2D_HPP
#define RAY_ENGINE_2D_HPP

#include "ObjectStorage_2D.hpp"
#include "Renderer_2D.hpp"


class RayEngine_2D{
private:
    // ObjectStorage_2D world;
    Renderer_2D renderer;
    bool drawFrame;
public:
    RayEngine_2D(sf::RenderWindow& window);
    void init(int renderMode);
    void handleInput();
    void renderLoop();
    void exit();
};



#endif //RAY_ENGINE_2D_HPP