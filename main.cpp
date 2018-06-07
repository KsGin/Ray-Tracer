#include <iostream>
#include <SDL2/SDL.h>
#include "headers/device.h"
#include "headers/sphere.h"
#include "headers/camera.h"
#include "headers/intersect.h"

using namespace Math;

const int width = 800;
const int height = 600;
const bool isScreenFull = false;

int main() {

    Device *device = new Device();

    device->initialize(width, height, isScreenFull);

    device->show();

    while (!device->windowShouldClose()) {

        Sphere *sphere = new Sphere(Vector3(0, 0, 0), 1);
        Camera *camera = new PerspectiveCamera(70, Vector3(3, 3, 3), Vector3(0, 0, 0), Vector3(0, 1, 0));

        for (int i = 0; i < width; ++i) {
            float sx = i / (float) width;
            for (int j = 0; j < height; ++j) {
                float sy = j / (float) height;
                Ray ray = camera->generateRay(sx, sy);
//                std::cout << sx << " " << sy << std::endl;
                IntersectResult intersectResult = Intersect::intersect(ray, *sphere);
                if (intersectResult.isHit) {
                    float depth = intersectResult.distance / 10;
                    device->setPixelColor(i, j, Color(depth, depth, 0, 1));
                }
            }
        }

        device->updateRender();
    }

    device->destory();

    return 0;
}