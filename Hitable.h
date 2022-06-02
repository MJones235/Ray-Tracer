#include "Ray.h"

class Hitable {
    public:
        virtual double hit(const Ray& ray) const = 0;
        virtual ~Hitable() =default;
};