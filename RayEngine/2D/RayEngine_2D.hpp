#ifndef RAY_ENGINE_2D_HPP
#define RAY_ENGINE_2D_HPP

#include "2D/WorldEnviroment_2D.hpp"
#include "2D/Renderer_2D.hpp"
#include "InputRecorder.hpp"
#include "MathEngine.hpp"


class RayEngine{
private:
    WorldEnviroment_2D world;
    Renderer_2D renderer;
    InputRecorder inputRecorder;
    bool drawFrame;
public:
    RayEngine();
    void initiate();
    void handleInput();
    void renderLoop();
};



#endif //RAY_ENGINE_2D_HPP