#ifndef RAY_CASTER_2D_HPP
#define RAY_CASTER_2D_HPP

#include "Ray_2D.hpp"
#include "GeometricObject_2D.hpp"
#include "Light_2D.hpp"

class RayCaster_2D{
private:
    std::shared_ptr<std::vector<Light_2D>> lightVector;
    std::shared_ptr<std::vector<GeometricObject_2D>> geometricObjects;
public:
    RayCaster_2D(std::shared_ptr<std::vector<Light_2D>> lightVector, std::shared_ptr<std::vector<GeometricObject_2D>> geometricObjects);
    void castRays(float (&colorBuffer)[WINDOW_PIXEL_COUNT * 4]);
    float lightAttenuation(float distance);
};

#endif //RAY_CASTER_2D_HPP