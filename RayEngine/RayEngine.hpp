#ifndef RAY_ENGINE
#define RAY_ENGINE

#include "WorldEnviroment.hpp"
#include "Renderer.hpp"
#include "InputRecorder.hpp"
#include "MathEngine.hpp"


class RayEngine{
private:
    WorldEnviroment world;
    Renderer renderer;
    InputRecorder inputRecorder;
    bool drawFrame;
public:
    RayEngine();
    void initiate();
    void handleInput();
    void renderLoop();
};



#endif //RAY_ENGINE