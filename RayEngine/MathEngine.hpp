#ifndef MATH_ENGINE_HPP
#define MATH_ENGINE_HPP

#include "masterInclude.hpp"
#include <math.h>

namespace mathEngine{
    sf::Vector3f dotProduct();
    sf::Vector3f crossProduct();
    float getVectorLength();
    float lightAttenuation(float distance);
};

#endif //MATH_ENGINE_HPP