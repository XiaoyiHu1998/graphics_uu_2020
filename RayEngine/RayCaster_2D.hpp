#ifndef RAY_CASTER_2D_HPP
#define RAY_CASTER_2D_HPP

#include "Ray_2D.hpp"

class RayCaster_2D{
private:
    sf::Vector2f cameraOrigin;
    float screenDistance;
    WorldEnviroment_2D* worldPointer;
public:
    RayCaster_2D(sf::Vector2f cameraOrigin, float screenDistance):cameraOrigin{cameraOrigin}, screenDistance{screenDistance}{}
    RayCaster_2D(sf::Vector2f cameraOrigin, float screenDistance, WorldEnviroment_2D* worldPointer);
    void castPrimaryRay();
    void castShadowRay();
    void castRays(float* floatArrayPointer);
    float lightAttenuation(float distance);
};

#endif //RAY_CASTER_2D_HPP