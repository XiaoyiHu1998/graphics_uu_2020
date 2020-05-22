#ifndef OBJECT_STORAGE_2D_HPP
#define OBJECT_STORAGE_2D_HPP

#include "Light_2D.hpp"
#include "Circle_2D.hpp"

class ObjectStorage_2D{
private:
    std::vector<Light_2D> lightVector;
    std::vector<std::shared_ptr<Circle_2D>> objects;
public:
    ObjectStorage_2D();
    void init();
    void import();
    std::vector<Light_2D>& getLightVector();
    std::vector<std::shared_ptr<Circle_2D>>& getobjects();
};

#endif //OBJECT_STORAGE_2D_HPP