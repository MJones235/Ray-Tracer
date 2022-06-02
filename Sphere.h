#ifndef SPHERE_H
#define SPHERE_H

#include "Ray.h"
#include "Vector3D.h"
#include "Hitable.h"

class Sphere : public Hitable {
    public:
        Sphere() = default;
        Sphere(Point c, double r) : center{c}, radius{r} {};
        double hit(const Ray& ray) const override;

        Direction surfaceNormal(Point point) {
            return (point - center).normalised();
        }

    private:
        Point center {Point(0, 0, 0)};
        double radius {0.0};
};

#endif