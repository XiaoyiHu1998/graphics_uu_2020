#ifndef CIRCLE_2D_HPP
#define CIRCLE_2D_HPP

#include "Object_2D.hpp"
#include "math.h"

struct implicitCircle{
    float xTerm;
    float yTerm;
    float spinRadius;
    float angle;
};

class Circle_2D : public Object_2D{
private:
    float radius;
    implicitCircle implicitForm;
    float angle;
    float spinRadius;
    sf::Vector2f spinPosition;
public:
    Circle_2D(const sf::Vector2f & position, float radius, float spinRadius = 50, float angle = 0):
    Object_2D{position},
    radius{radius},
    spinRadius{spinRadius},
    angle{angle}
    {
        spinPosition = position;
    }

    float getRadius() override {
        return radius;
    }

    sf::Vector2f getPosition() override {
        return spinPosition;
    }

    void updatePosition() override{
        angle += 0.05;
        spinPosition.x = position.x + spinRadius * cos(angle);
        spinPosition.y = position.y + spinRadius * sin(angle);
    }
};

#endif