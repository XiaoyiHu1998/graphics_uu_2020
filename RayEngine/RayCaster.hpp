#ifndef RAY_CASTER
#define RAY_CASTER

#include "masterInclude.hpp"
#include "WorldEnviroment.hpp"

class RayCaster{
private:
    sf::Vector3f originPosition;
    float screenDistance();
    std::shared_ptr<WorldEnviroment> worldPointer;
public:
    RayCaster(std::shared_ptr<WorldEnviroment> worldPointer);
    void castPrimaryRay();
    void castShadowRay();
    void castRays();
};

#endif //RAY_CASTER