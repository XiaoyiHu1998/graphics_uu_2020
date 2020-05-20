#ifndef OBJECT_STORAGE_2D_HPP
#define OBJECT_STORAGE_2D_HPP

#include "Light_2D.hpp"
#include "GeometricObject_2D.hpp"

class ObjectStorage_2D{
private:
    std::vector<Light_2D> lightVector;
    std::vector<GeometricObject_2D> geometricObjects;
public:
    ObjectStorage_2D();
    void init();
    void import();
    std::vector<Light_2D> getLightVector();
    std::vector<GeometricObject_2D> getGeometricObjects();
};

#endif //OBJECT_STORAGE_2D_HPP