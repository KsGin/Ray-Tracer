#include <iostream>
#include <SDL2/SDL.h>
#include "headers/device.h"
#include "headers/sphere.h"
#include "headers/camera.h"
#include "headers/intersect.h"
#include "headers/scene.h"

using namespace Math;
using namespace std;

const int width = 800;
const int height = 600;
const bool isScreenFull = false;

int main() {

    Device *device = new Device();

    device->initialize(width, height, isScreenFull);

    device->show();

    Camera *camera = new PerspectiveCamera(90, Vector3(5, 5, 5), Vector3(0, 0, 0), Vector3(0, 1, 0));

    vector<Sphere> models = vector<Sphere>(0);
    models.push_back(Sphere(Vector3(0, 0, 0), 1));
    models.push_back(Sphere(Vector3(0, 3, 0), 1));
    models.push_back(Sphere(Vector3(0, -3, 0), 1));
    models.push_back(Sphere(Vector3(-3, 0, 0), 1));
    models.push_back(Sphere(Vector3(3, 0, 0), 1));

    Scene *scene = new Scene(models, camera, width, height);

    while (!device->windowShouldClose()) {

        scene->RenderScene(device);

        device->updateRender();
    }

    device->destory();

    delete scene;

    return 0;
}