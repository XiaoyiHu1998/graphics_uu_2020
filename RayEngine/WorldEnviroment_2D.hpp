#ifndef WORLD_ENVIROMENT_2D_HPP
#define WORLD_ENVIROMENT_2D_HPP

#include "Light_2D.hpp"
#include "GeometricObject_2D.hpp"

class WorldEnviroment_2D{
private:
    std::vector<Light_2D> lightVector;
    std::vector<GeometricObject_2D> geometricObjects;
public:
    WorldEnviroment_2D();
    void init();
    void import();
    std::shared_ptr<std::vector<Light_2D>> getLightVector();
    std::shared_ptr<std::vector<GeometricObject_2D>> getGeometricObjects();
};

#endif //WORLD_ENVIROMENT_2D_HPP