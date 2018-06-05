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
        Camera *camera = new PerspectiveCamera(90, Vector3(0, 5, -5), Vector3(0, 0, 0), Vector3(0, 1, 0));

        for (int i = 0; i < height; ++i) {
            float sy = 1 - i / (float)height;
            for (int j = 0; j < width; ++j) {
                float sx = j / (float)width;
                Ray r = camera->generateRay(sx, sy);

                IntersectResult ir = Intersect::intersect(r, *sphere);
                if (ir.isHit) {
                    device->setPixelColor(j , i, Color(0, 1, 1, 1));
                }
            }
        }

        device->updateRender();
    }

    device->destory();

    return 0;
}