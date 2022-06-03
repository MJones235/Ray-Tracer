#ifndef SPHERE_H
#define SPHERE_H

#include "Ray.h"
#include "Vector3D.h"
#include "Hittable.h"
#include <memory>

class Sphere : public Hittable {
    public:
        Sphere() {};
        Sphere(Point c, double r, std::shared_ptr<Material> m) 
            : center{c}, radius{r}, materialPtr{m} {};
        
        bool hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const override;

        Direction surfaceNormal(Point point) const {
            return (point - center).normalised();
        }

        Point center {Point(0, 0, 0)};
        double radius {0.0};
        std::shared_ptr<Material> materialPtr;

        void updateRecord(HitRecord& record, const Ray& ray, double t) const;
};

#endif