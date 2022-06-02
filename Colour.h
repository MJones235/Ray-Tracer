#ifndef COLOUR_H
#define COLOUR_H

#include "Vector3D.h"

#include <iostream>

inline void writeColour(std::ostream &out, Colour colour) {
    out << static_cast<int>(255.999 * colour.x) << ' '
        << static_cast<int>(255.999 * colour.y) << ' '
        << static_cast<int>(255.999 * colour.z) << '\n';
}

#endif