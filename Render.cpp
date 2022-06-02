#include "Render.h"
#include "Colour.h"
#include "Vector3D.h"

void render() {
    const int width = 255;
    const int height = 255;

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Colour colour(double(i)/height, double(j)/width, 0.25);
            writeColour(std::cout, colour);
        }
    }
}