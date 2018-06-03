#include <iostream>
#include <SDL2/SDL.h>
#include "headers/device.h"

const int width = 800;
const int height = 600;
const bool isScreenFull = false;

int main() {

    Device *device = new Device();

    device->initialize(width, height, isScreenFull);

    device->show();

    while (!device->windowShouldClose()) {

        for (int i = 100; i < width - 100; ++i) {
            device->setPixelColor(i, 200, Color(1.0, 0.0, 0.0, 1.0));
        }

        device->updateRender();
    }

    device->destory();

    return 0;
}