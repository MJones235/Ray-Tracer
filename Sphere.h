#ifndef SPHERE_H
#define SPHERE_H

#include "Ray.h"
#include "Vector3D.h"
#include "Hitable.h"

class Sphere : public Hitable {
    public:
        Sphere() = default;
        Sphere(Point c, double r) : center{c}, radius{r} {};
        bool hit(const Ray& ray) const override;

    private:
        Point center {Point(0, 0, 0)};
        double radius {0.0};
};

#endif