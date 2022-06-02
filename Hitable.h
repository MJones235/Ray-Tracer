#include "Ray.h"

class Hitable {
    public:
        virtual bool hit(const Ray& ray) const = 0;
        virtual ~Hitable() =default;
};