#ifndef OBJECT_2D_HPP
#define OBJECT_2D_HPP

#include "masterInclude.hpp"

class Object_2D{
protected:
    sf::Vector2f position;
public:
    Object_2D(const sf::Vector2f & position):
        position{position}
    {}
    
    virtual float getRadius(){return 0;}
    virtual sf::Vector2f getPosition(){return sf::Vector2f();};
};


#endif //OBJECT_2D_HPP