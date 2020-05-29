#ifndef RAY_CASTER_2D_HPP
#define RAY_CASTER_2D_HPP

#include "Ray_2D.hpp"
#include "Object_2D.hpp"
#include "Light_2D.hpp"
#include "Color.hpp"

class RayCaster_2D{
private:
    unsigned int threadCount;
public:
    RayCaster_2D(unsigned int threadCount);
    void castRays(std::vector<Light_2D> & lightVector, std::vector<std::shared_ptr<Circle_2D>> & objects, std::vector<float> & colorBuffer, int threadNumber, std::mutex& bufferMutex);
    void castRaysMT(std::vector<Light_2D>& lightVector, std::vector<std::shared_ptr<Circle_2D>>& objects, std::vector<float>& colorBuffer, int threadNumber, std::vector<bool>& render, std::mutex& renderMutex, std::mutex& bufferMutex);
    float lightAttenuation(float distance);
};

#endif //RAY_CASTER_2D_HPP