#ifndef RAY_CASTER_HPP
#define RAY_CASTER_HPP

#include "masterInclude.hpp"
#include "WorldEnviroment.hpp"
#include "Ray.hpp"

class RayCaster{
private:
    sf::Vector3f cameraOrigin;
    float screenDistance;
    std::shared_ptr<WorldEnviroment> worldPointer;
public:
    RayCaster(sf::Vector3f cameraOrigin, float screenDistance, std::shared_ptr<WorldEnviroment> worldPointer);
    void castPrimaryRay();
    void castShadowRay();
    void castRays(float* floatArrayPointer);
};

#endif //RAY_CASTER_HPP