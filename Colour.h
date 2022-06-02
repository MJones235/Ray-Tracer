#ifndef COLOUR_H
#define COLOUR_H

#include "Vector3D.h"
#include "Utils.h"

#include <iostream>

inline int getColourValue(double x) {
    return static_cast<int>(256 * clamp(x, 0.0, 0.999)); 
}

inline void writeColour(std::ostream &out, Colour colour, int samples) {

    double scale = 1.0 / samples;

    double r = colour.x * scale;
    double g = colour.y * scale;
    double b = colour.z * scale;

    out << getColourValue(r) << ' '
        << getColourValue(g) << ' '
        << getColourValue(b) << '\n';
}

#endif