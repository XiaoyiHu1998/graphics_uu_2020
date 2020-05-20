#ifndef RAY_CASTER_2D_HPP
#define RAY_CASTER_2D_HPP

#include "2D/Ray_2D.hpp"

class RayCaster_2D{
private:
    sf::Vector3f cameraOrigin;
    float screenDistance;
    std::shared_ptr<WorldEnviroment_2D> worldPointer;
public:
    RayCaster_2D(sf::Vector3f cameraOrigin, float screenDistance, std::shared_ptr<WorldEnviroment_2D> worldPointer);
    void castPrimaryRay();
    void castShadowRay();
    void castRays(float* floatArrayPointer);
};

#endif //RAY_CASTER_2D_HPP