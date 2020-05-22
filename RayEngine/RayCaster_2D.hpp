#ifndef RAY_CASTER_2D_HPP
#define RAY_CASTER_2D_HPP

#include "Ray_2D.hpp"
#include "Object_2D.hpp"
#include "Light_2D.hpp"

class RayCaster_2D{
private:
    unsigned int threadCount;
public:
    RayCaster_2D(unsigned int threadCount);
    std::unique_ptr<float[]> castRays(std::vector<Light_2D> & lightVector, std::vector<Object_2D> & objects);
    float lightAttenuation(float distance);
};

#endif //RAY_CASTER_2D_HPP