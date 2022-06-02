#ifndef UTILS_H
#define UTILS_H

#include "Constants.h"
#include <cstdlib>

inline bool isInRange(double value, double min, double max) {
    return value >= min && value <= max;
}

inline double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// return a random double in range [0, 1)
inline double randomDouble() {
    return rand() / (RAND_MAX + 1.0);
}

// return a random double in range [min, max)
inline double randomDouble(double min, double max) {
    return min + (max - min)*randomDouble();
}

inline double degreesToRadians(double degrees) {
    return degrees * pi / 180.0;
}

#endif

