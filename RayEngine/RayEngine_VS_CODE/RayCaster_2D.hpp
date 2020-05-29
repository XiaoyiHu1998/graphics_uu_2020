#ifndef RAY_CASTER_2D_HPP
#define RAY_CASTER_2D_HPP

#include "Ray_2D.hpp"
#include "Object_2D.hpp"
#include "Light_2D.hpp"
#include "Color.hpp"

class RayCaster_2D{
private:
    unsigned int threadCount;
    std::mutex bufferMutex;
    std::mutex renderMutex;
    std::mutex finishMutex;
public:
    RayCaster_2D(unsigned int threadCount);
    void castRays(std::vector<Light_2D> & lightVector, std::vector<std::shared_ptr<Circle_2D>> & objects, std::vector<float> & colorBuffer, int threadNumber);
    void castRaysMT(std::vector<Light_2D>& lightVector, std::vector<std::shared_ptr<Circle_2D>>& objects, std::vector<float>& colorBuffer, int threadNumber, bool& render, int& finishedThreads);
    float lightAttenuation(float distance);
};

#endif //RAY_CASTER_2D_HPP