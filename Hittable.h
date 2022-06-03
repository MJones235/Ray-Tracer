#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"
#include "Vector3D.h"
#include "Material.h"


class Hittable {
    public:
        virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const = 0;
        virtual ~Hittable() =default;
};

#endif