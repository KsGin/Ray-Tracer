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

    Camera *camera = new PerspectiveCamera(90, Vector3(0, 3, 10), Vector3(0, 0, 0), Vector3(0, 1, 0), 0.01, 50);

    vector<Sphere *> spheres = vector<Sphere *>(0);
    spheres.push_back(new Sphere(Vector3(0, 2, 0), 2));
    spheres.push_back(new Sphere(Vector3(5, 2, 2), 2));
    spheres.push_back(new Sphere(Vector3(-5, 2, 2), 2));

    vector<Plane *> planes = vector<Plane *>(0);
    planes.push_back(new Plane(Vector3(0, 1, 0), 0));

    DirectionLight *dLight = new DirectionLight(Vector3(0, -1, 0).normalize(), Color(1, 1, 1, 1), 1, 1, 32);

    Scene *scene = new Scene(spheres, planes, camera, dLight, width, height);


    while (!device->windowShouldClose()) {

        scene->renderScene(device, 3);

        device->updateRender();

    }

    device->destory();

    for (auto sphere : spheres) {
        if (sphere) {
            delete sphere;
            sphere = 0;
        }
    }
    for (auto plane : planes) {
        if (plane) {
            delete plane;
            plane = 0;
        }
    }
    delete camera;
    delete dLight;
    delete scene;

    return 0;
}