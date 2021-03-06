#ifndef MATERIAL_H
#define MATERIAL_H

#include "Ray.h"
#include "Vector3D.h"
#include <memory>

using std::shared_ptr;

class Material;

struct HitRecord {
    Point point;
    Direction normal;
    shared_ptr<Material> materialPtr;
    double t;
    bool outerSurface;

    inline void setSurfaceNormal(const Ray& ray, const Direction& outwardNormal) {
        outerSurface = dot(ray.direction(), outwardNormal) < 0;
        normal = outerSurface ? outwardNormal : -outwardNormal;
    }
};

class Material {
    public:
        virtual bool scatter(
            const Ray& rayIn,
            const HitRecord record,
            Colour& attenuation,
            Ray& scattered
        ) const = 0;
};

class Lambertian : public Material {
    public:
        Lambertian(const Colour& a) : albedo(a) {}

        virtual bool scatter(
            const Ray& rayIn,
            const HitRecord record,
            Colour& attenuation,
            Ray& scattered
        ) const override {
            Direction scatterDirection = record.normal + randomNormalisedVectorInUnitSphere();
            
            if (scatterDirection.isNearZero()) scatterDirection = record.normal;
            
            scattered = Ray(record.point, scatterDirection);
            attenuation = albedo;
            return true;
        }

        Colour albedo;
};

class Metal : public Material {
    public:
        Metal(const Colour& a, double f) : albedo(a), fuzz{f < 1 ? f : 1} {}

        virtual bool scatter(
            const Ray& rayIn,
            const HitRecord record,
            Colour& attenuation,
            Ray& scattered
        ) const override {
            Direction reflected = reflect(rayIn.normalisedDirection(), record.normal);
            scattered = Ray(record.point, reflected + fuzz * randomNormalisedVectorInUnitSphere());
            attenuation = albedo;
            return (dot(scattered.direction(), record.normal) > 0);
        }

        Colour albedo;
        double fuzz;
};

class Dielectric : public Material {
    public: 
        Dielectric(double ri) : refractiveIndex{ri} {}

        virtual bool scatter(
            const Ray& rayIn,
            const HitRecord record,
            Colour& attenuation,
            Ray& scattered
        ) const override {
            attenuation = Colour(1, 1, 1);
            double refractionRatio = record.outerSurface ? 1 / refractiveIndex : refractiveIndex;

            double cosTheta = getCosTheta(-rayIn.normalisedDirection(), record.normal);
            double sinTheta = getSinTheta(-rayIn.normalisedDirection(), record.normal);

            bool cannotRefract = refractionRatio * sinTheta > 1;
            
            Direction direction = cannotRefract 
                ? reflect(rayIn.normalisedDirection(), record.normal) 
                : refract(rayIn.normalisedDirection(), record.normal, refractionRatio);

            
            scattered = Ray(record.point, direction);
            return true;
        }

        double refractiveIndex;
};

#endif