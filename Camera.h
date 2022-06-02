#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"
#include "Vector3D.h"

class Camera {
    public:
        Camera() {
            auto aspectRatio = 16.0 / 9.0;
            auto viewportHeight = 2.0;
            auto viewportWidth = aspectRatio * viewportHeight;
            auto focalLength = 1.0;

            origin = Point(0, 0, 0);
            xAxis = Direction(viewportWidth, 0.0, 0.0);
            yAxis = Direction(0.0, viewportHeight, 0.0);
            zAxis = Direction(0.0, 0.0, focalLength);
            lowerLeftCorner = origin - xAxis/2 - yAxis/2 - zAxis;
        }

        Ray getRay(double scaledX, double scaledY) const {
            return Ray(origin, lowerLeftCorner + xAxis * scaledX + yAxis * scaledY - origin);
        }
    private:
        Point origin;
        Point lowerLeftCorner;
        Direction xAxis;
        Direction yAxis;
        Direction zAxis;
};

#endif