#ifndef COLOR_HPP
#define COLOR_HPP

#include "masterInclude.hpp"

struct Color{
    float r;
    float g;
    float b;
    float a;

    Color(float r, float g, float b):
        r{r},
        g{g},
        b{b},
        a{1.0f}
    {}
};

#endif