#ifndef OBJECT_2D_HPP
#define OBJECT_2D_HPP

#include "masterInclude.hpp"

class Object_2D{
protected:
    sf::Vector2f position;
public:
    Object_2D(const sf::Vector2f & position):
        position{sf::Vector2f(position.x, position.y)}
    {}
    
    virtual float getRadius(){return 0;}
    virtual sf::Vector2f getPosition(){return position;};
    virtual void updatePosition(){};
};


#endif //OBJECT_2D_HPP