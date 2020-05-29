#ifndef COLOR_HPP
#define COLOR_HPP

#include "masterInclude.hpp"

class Color{
private:
    sf::Vector3f colorHDR;
    sf::Vector3i colorSDR[3];
public:
    Color(float ColorHDR[3]);
    Color(uint8_t ColorSDR[3]);
    void updateColor(float colorHDR[3]);
    void updateColor(uint8_t colorSDR[3]);
    sf::Vector3f getColorHDR();
    sf::Vector3i getColorSDR();
};

#endif