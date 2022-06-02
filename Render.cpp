#include "Render.h"
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

    double scaledY = ray.direction().normalised().y;
    // scale from -1 <= y <= 1 to 0 <= scaledY <= 1
    return Colour(1.0, 1.0, 1.0) * scaledY + Colour(0.5, 0.7, 1.0) * (1 - scaledY);
}

void render() {
    // image dimensions
    const double aspectRatio = 16.0 / 9.0;
    const int imageWidth = 600;
    const int imageHeight = static_cast<int>(imageWidth / aspectRatio);

    // camera constants
    const double viewportHeight = 2.0;
    const double viewportWidth = viewportHeight * aspectRatio;
    const double focalLength = 1.0;

    // axes
    const Point origin = Point(0, 0, 0);
    const Direction xAxis = Direction(viewportWidth, 0, 0);
    const Direction yAxis = Direction(0, viewportHeight, 0);
    const Direction zAxis = Direction(0, 0, focalLength);
    const Point lowerLeftCorner = origin - xAxis/2 - yAxis/2 - zAxis;

    // world
    HittableList world;
    world.add(make_shared<Sphere>(Point(0, 0, -1), 0.5));
    world.add(make_shared<Sphere>(Point(0, 105, -1), 100));

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            double scaledX = double(j) / (imageWidth - 1);
            double scaledY = double(i) / (imageHeight - 1);
            Ray ray(origin, lowerLeftCorner + xAxis * scaledX + yAxis * scaledY - origin);
            Colour colour = rayColour(ray, world);
            writeColour(std::cout, colour);
        }
    }
}