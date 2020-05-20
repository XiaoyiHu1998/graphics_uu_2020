#ifndef RAY_CASTER_2D_HPP
#define RAY_CASTER_2D_HPP

#include "Ray_2D.hpp"
#include "GeometricObject_2D.hpp"
#include "Light_2D.hpp"

class RayCaster_2D{
private:
public:
    RayCaster_2D();
    std::unique_ptr<float[]> castRays(std::vector<Light_2D> lightVector, std::vector<GeometricObject_2D> geometricObjects);
    float lightAttenuation(float distance);
};

#endif //RAY_CASTER_2D_HPP