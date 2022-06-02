#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<typename T>
struct Vector3D {

    using Vector = Vector3D<T>;

    T x {0};
    T y {0};
    T z {0};

    Vector3D() {}
    Vector3D(T x, T y, T z) : x{x}, y{y}, z{z} {}
};

using Colour = Vector3D<double>;

#endif