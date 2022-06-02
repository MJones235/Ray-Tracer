#include "Sphere.h"
#include "Ray.h"
#include "Vector3D.h"

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

bool Sphere::hit(const Ray& ray) const {
    Direction ac = ray.origin() - center;
    double a = dot(ray.direction(), ray.direction());
    double b = 2 * dot(ray.direction(), ac);
    double c = dot(ac, ac) - radius*radius;
    
    double determinant = b*b - 4*a*c;

    return determinant >= 0;
}