#ifndef CIRCLE_2D_HPP
#define CIRCLE_2D_HPP

#include "Object_2D.hpp"

class Circle_2D : public Object_2D{
private:
    float radius;
public:
    Circle_2D(float radius):
    radius{radius}
    {}

    float getRadius(){
        return radius;
    }
};

#endif