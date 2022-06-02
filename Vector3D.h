#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

struct Vector {

    double x {0};
    double y {0};
    double z {0};

    Vector() {}
    Vector(double x, double y, double z) : x{x}, y{y}, z{z} {}

    double len() const;
    double lenSquared() const;
    Vector normalised() const;
};

inline double Vector::lenSquared() const {
    return x*x + y*y + z*z;
}

inline double Vector::len() const {
    return sqrt(lenSquared());
}

inline Vector Vector::normalised() const {
    double length = len();
    return Vector(x/length, y/length, z/length);
}

inline Vector operator*(const Vector &vector, const double scalar) {
    return Vector(vector.x*scalar, vector.y*scalar, vector.z*scalar);
}

inline Vector operator/(const Vector &vector, const double scalar) {
    if (scalar == 0) return Vector();

    return Vector(vector.x/scalar, vector.y/scalar, vector.z/scalar);
}

inline Vector operator+(const Vector &u, const Vector &v) {
    return Vector(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline Vector operator-(const Vector &u, const Vector &v) {
    return Vector(u.x - v.x, u.y - v.y, u.z - v.z);
}


using Colour = Vector;
using Point = Vector;
using Direction = Vector;

#endif