#ifndef MATH_ENGINE
#define MATH_ENGINE

#include "masterInclude.hpp"
#include <math.h>

class MathEngine{
private:
public:
    MathEngine();
    sf::Vector3f dotProduct();
    sf::Vector3f crossProduct();
    float getVectorLength();
    
};


#endif //MATH_ENGINE