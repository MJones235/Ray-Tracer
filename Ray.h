#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"

/*

Ray is a line of the form Ray(t) = A + Bt

A is the position vector of the origin of the ray
B is the direction vector of the ray

*/

struct Ray {
    Ray() {}
    Ray(const Point& origin, const Direction& direction) : A{origin}, B{direction} {}

    Point A;
    Direction B;

    const Point& origin() const { return A; }
    const Direction& direction() const { return B; }

    Direction normalisedDirection() const { return direction().normalised(); }

    Point pointAtT(double t) const { return A + B*t; }
};

#endif