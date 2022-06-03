#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

#include "Utils.h"

struct Vector {

    double x {0};
    double y {0};
    double z {0};

    Vector() {}
    Vector(double x, double y, double z) : x{x}, y{y}, z{z} {}

    inline static Vector random() {
        return Vector(randomDouble(), randomDouble(), randomDouble());
    }

    inline static Vector random(double min, double max) {
        return Vector(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
    }

    inline Vector operator-() const { return Vector(-x, -y, -z); }

    Vector& operator+=(const Vector& v);

    double len() const;
    double lenSquared() const;
    Vector normalised() const;

    inline bool isNearZero() const {
        const double s = 2e-8;
        return len() < s;
    }
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

inline Vector operator*(const double scalar, const Vector &vector) {
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

inline Vector operator*(const Vector &u, const Vector &v) {
    return Vector(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline Vector& Vector::operator+=(const Vector &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline double dot(const Vector &u, const Vector &v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline Vector randomVectorInUnitSphere() {
    while (true) {
        Vector random = Vector::random(-1, 1);
        if (random.lenSquared() <= 1) return random;
        else continue;
    }
}

inline Vector randomNormalisedVectorInUnitSphere() {
    return randomVectorInUnitSphere().normalised();
}

inline Vector reflect(const Vector& v, const Vector& n) {
    return v - 2*dot(v, n)*n;
}


using Colour = Vector;
using Point = Vector;
using Direction = Vector;

#endif