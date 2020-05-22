#ifndef CIRCLE_2D_HPP
#define CIRCLE_2D_HPP

#include "Object_2D.hpp"

struct implicitCircle{
    float xTerm;
    float yTerm;
    float radiusTerm;
};

class Circle_2D : public Object_2D{
private:
    float radius;
    implicitCircle implicitForm;
public:
    Circle_2D(const sf::Vector2f & position, float radius):
    Object_2D{position},
    radius{radius}
    {
    }

    float getRadius(){
        return radius;
    }
};

#endif