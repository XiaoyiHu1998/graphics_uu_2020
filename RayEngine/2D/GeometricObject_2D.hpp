#ifndef GEOMETRIC_OBJECT_2D_HPP
#define GEOMETRIC_OBJECT_2D_HPP

#include "Object.hpp"

class GeometricObject_2D : public Object{
private:
    sf::Vector3f position;
    std::vector<sf::Vector3f> geometry;
    Color color;
public:
    GeometricObject_2D();
};


#endif //GEOMETRIC_OBJECT_HPP