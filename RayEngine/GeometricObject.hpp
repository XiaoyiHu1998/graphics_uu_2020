#ifndef GEOMETRIC_OBJECT_HPP
#define GEOMETRIC_OBJECT_HPP

#include "Object.hpp"

class GeometricObject : public Object{
private:
    sf::Vector3f position;
    std::vector<sf::Vector3f> geometry;
    Color color;
public:
    GeometricObject();
};


#endif //GEOMETRIC_OBJECT_HPP