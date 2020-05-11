#ifndef WORLD_ENVIROMENT_HPP
#define WORLD_ENVIROMENT_HPP

#include "Light.hpp"
#include "GeometricObject.hpp"

class WorldEnviroment{
private:
    std::vector<Light> lightVector;
    std::vector<GeometricObject> geometricObjects;
public:
    WorldEnviroment();
    void import();
    std::shared_ptr<std::vector<Light>> getLightVector();
    std::shared_ptr<std::vector<GeometricObject>> getGeometricObjects();
};

#endif //WORLD_ENVIROMENT_HPP