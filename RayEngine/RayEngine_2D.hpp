#ifndef RAY_ENGINE_2D_HPP
#define RAY_ENGINE_2D_HPP

#include "WorldEnviroment_2D.hpp"
#include "Renderer_2D.hpp"
#include "InputRecorder.hpp"


class RayEngine_2D{
private:
    WorldEnviroment_2D world;
    Renderer_2D renderer;
    InputRecorder inputRecorder;
    bool drawFrame;
public:
    RayEngine_2D();
    void init();
    void handleInput();
    void renderLoop();
};



#endif //RAY_ENGINE_2D_HPP