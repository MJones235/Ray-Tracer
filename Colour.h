#ifndef COLOUR_H
#define COLOUR_H

#include "Vector3D.h"
#include "Utils.h"

#include <cmath>
#include <iostream>

inline int getColourValue(double x) {
    return static_cast<int>(256 * clamp(x, 0.0, 0.999)); 
}

// divide by number of samples and gamma correct for gamma = 2
inline double scaleAndGammaCorrect(double x, int samples) {
    return sqrt(x / samples);
}

inline void writeColour(std::ostream &out, Colour colour, int samples) {
    // Divide the colour by the number of samples and gamma-correct for gamma=2.0.
    double scale = 1.0 / samples;

    double r = scaleAndGammaCorrect(colour.x, samples);
    double g = scaleAndGammaCorrect(colour.y, samples);
    double b = scaleAndGammaCorrect(colour.z, samples);

    out << getColourValue(r) << ' '
        << getColourValue(g) << ' '
        << getColourValue(b) << '\n';
}

#endif