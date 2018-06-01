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
        device->updateRender();
    }

    device->destory();

    return 0;
}