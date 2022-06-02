#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"
#include "Vector3D.h"

struct HitRecord {
    Point point;
    Direction normal;
    double t;
    bool outerSurface;

    inline void setSurfaceNormal(const Ray& ray, const Direction& outwardNormal) {
        outerSurface = dot(ray.direction(), outwardNormal) < 0;
        normal = outerSurface ? outwardNormal : -outwardNormal;
    }
};


class Hittable {
    public:
        virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const = 0;
        virtual ~Hittable() =default;
};

#endif