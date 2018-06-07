#include <iostream>
#include <SDL2/SDL.h>
#include "headers/device.h"
#include "headers/sphere.h"
#include "headers/camera.h"
#include "headers/intersect.h"
#include "headers/scene.h"
#include "include/math/matrix.hpp"

using namespace Math;
using namespace std;

const int width = 800;
const int height = 600;
const bool isScreenFull = false;

int main() {

    Device *device = new Device();

    device->initialize(width, height, isScreenFull);

    device->show();

    Camera *camera = new PerspectiveCamera(90, Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));

    vector<Sphere*> models = vector<Sphere*>(0);
    models.push_back(new Sphere(Vector3(0, 2, 0), 2));
//    models.push_back(Sphere(Vector3(0, 3, 0), 1));
//    models.push_back(Sphere(Vector3(0, -3, 0), 1));
//    models.push_back(Sphere(Vector3(-3, 0, 0), 1));
//    models.push_back(Sphere(Vector3(3, 0, 0), 1));

    Plane *plane = new Plane(Vector3(0, 1, 0), 0);

    Scene *scene = new Scene(models, camera, plane, width, height);

    while (!device->windowShouldClose()) {

        scene->RenderScene(device);

        device->updateRender();
    }

    device->destory();

    delete scene;

    return 0;
}