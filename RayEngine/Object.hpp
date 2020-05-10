#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "masterInclude.hpp"
#include "Color.hpp"

class Object{
private:
    string objectType;
public:
    Object();
    string getObjectType();
};

#endif //OBJECT_HPP