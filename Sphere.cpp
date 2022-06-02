#include "Sphere.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Utils.h"
#include <math.h>

/*

Ray hits surface of sphere if there is a value, t, that satisfies

length(R(t) - C) = r

R is ray
C is center of sphere
r is radius of sphere

Given that R(t) = A + tB, this equation can be manipulated to reach

t^2(B*B) + 2tB*(A - C) + (A - C)*(A - C) - r^2 = 0

and this can be solved using the quadratic formula

*/

bool Sphere::hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const {
    Direction ac = ray.origin() - center;
    double a = ray.direction().lenSquared();
    double b = 2 * dot(ray.direction(), ac);
    double c = ac.lenSquared() - radius*radius;
    
    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) return false;

    double rootLow = (-b - sqrt(b*b - 4*a*c)) / (2*a);

    if (isInRange(rootLow, tMin, tMax)) {
        updateRecord(record, ray, rootLow);
        return true;
    }

    double rootHigh = (-b + sqrt(b*b - 4*a*c)) / (2*a);

    if (isInRange(rootHigh, tMin, tMax)) {
        updateRecord(record, ray, rootHigh);
        return true;
    }

    return false;
};

void Sphere::updateRecord(HitRecord& record, const Ray& ray, double t) const {
    Point hitPoint = ray.pointAtT(t);
            
    record.t = t;
    record.point = hitPoint;
    record.setSurfaceNormal(ray, surfaceNormal(hitPoint));
}