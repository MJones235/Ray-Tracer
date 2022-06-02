#ifndef SPHERE_H
#define SPHERE_H

#include "Ray.h"
#include "Vector3D.h"
#include "Hittable.h"

class Sphere : public Hittable {
    public:
        Sphere() {};
        Sphere(Point c, double r) : center{c}, radius{r} {};
        
        bool hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const override;

        Direction surfaceNormal(Point point) const {
            return (point - center).normalised();
        }

    private:
        Point center {Point(0, 0, 0)};
        double radius {0.0};

        void updateRecord(HitRecord& record, const Ray& ray, double t) const;
};

#endif