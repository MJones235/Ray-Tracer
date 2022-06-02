#include "Render.h"
#include "Camera.h"
#include "Colour.h"
#include "Constants.h"
#include "Hittable.h"
#include "HittableList.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vector3D.h"
#include <iostream>
#include <memory>

using std::make_shared;

Colour rayColour(const Ray& ray, const Hittable& world) {
    HitRecord record;
    if (world.hit(ray, 0, infinity, record)) {
        return (record.normal + Colour(1,1,1)) / 2;
    }

    // scale from -1 <= y <= 1 to 0 <= t <= 1
    double y = ray.direction().normalised().y;
    double t = (y + 1) / 2;

    return Colour(1.0, 1.0, 1.0) * (1 - t) + Colour(0.5, 0.7, 1.0) * t;
}

void render() {
    // image dimensions
    const double aspectRatio = 16.0 / 9.0;
    const int imageWidth = 600;
    const int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    const int samplesPerPixel = 100;

    // camera
    Camera camera;

    // world
    HittableList world;
    world.add(make_shared<Sphere>(Point(0, 0, -1), 0.5));
    world.add(make_shared<Sphere>(Point(0,-100.5,-1), 100));

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight - 1; j >= 0; --j) {
        for (int i = 0; i < imageWidth; ++i) {
            Colour pixelColour(0, 0 ,0);
            for (int s = 0; s < samplesPerPixel; ++s) {
                double scaledX = (i + randomDouble()) / (imageWidth - 1);
                double scaledY = (j + randomDouble()) / (imageHeight - 1);
                Ray ray = camera.getRay(scaledX, scaledY);
                pixelColour += rayColour(ray, world);
            }
            writeColour(std::cout, pixelColour, samplesPerPixel);
        }
    }
}