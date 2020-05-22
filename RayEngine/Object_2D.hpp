#ifndef OBJECT_2D_HPP
#define OBJECT_2D_HPP

#include "masterInclude.hpp"

class Object_2D{
private:
    sf::Vector2f position;
public:
    Object_2D(const sf::Vector2f & position):
        position{position}
    {};
};


#endif //OBJECT_2D_HPP