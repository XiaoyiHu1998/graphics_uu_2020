#ifndef WORLD_ENVIROMENT
#define WORLD_ENVIROMENT

#include "Light.hpp"
#include "GeometricObject.hpp"

class WorldEnviroment{
private:
    std::vector<Light> lightVector;
    std::vector<GeometricObject> geometricObjects;
public:
    WorldEnviroment();
    void import();
    std::shared_ptr<std::vector<Light>> getGeometricObjects();
    std::shared_ptr<std::vector<GeometricObject>> getLightVector();
};

#endif //WORLD_ENVIROMENT