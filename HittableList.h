#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "Hittable.h"
#include "Ray.h"

#include <memory>
#include <vector>

using std::shared_ptr;

class HittableList : public Hittable {
    public:
        HittableList() {}
        HittableList(shared_ptr<Hittable> object) { add(object); }

        std::vector<shared_ptr<Hittable>> objects;

        void clear() { objects.clear(); }
        void add(shared_ptr<Hittable> object) { objects.push_back(object); }

        virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const override;
};

inline bool HittableList::hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const {
    HitRecord tempRecord {record};
    double closest = tMax;

    for (const shared_ptr<Hittable>& object: objects) {
        if (object->hit(ray, tMin, closest, tempRecord)) {
            closest = tempRecord.t;
            record = tempRecord;
        }
    }
    return closest < tMax;
}

#endif