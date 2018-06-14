#include <iostream>
#include <SDL2/SDL.h>
#include "headers/device.h"
#include "headers/camera.h"
#include "headers/scene.h"
#include "include/math/matrix.hpp"
#include "headers/model.h"

using namespace Math;
using namespace std;

const int width = 800;
const int height = 600;
const bool isScreenFull = false;

int main() {

    Device *device = new Device();

    device->initialize(width, height, isScreenFull);

    device->show();

    Camera *camera = new PerspectiveCamera(90, Vector3(0, 3, -10), Vector3(0, 0, 0), Vector3(0, 1, 0), 0.01, 50);

    vector<Model *> models = vector<Model *>(0);
    models.push_back(new Sphere(Vector3(0, 2, 0), -2, 0.2, Color(1, 0, 0, 1)));
    models.push_back(new Sphere(Vector3(5, 2, 2), -2, 0.2, Color(0, 1, 0, 1)));
    models.push_back(new Sphere(Vector3(-5, 2, 2), -2, 0.2, Color(0, 0, 1, 1)));
    models.push_back(new Plane(Vector3(0, 1, 0), 0, 0.2, Color::black()));
//    models.push_back(new Plane(Vector3(0, 0, -1), -10, 0.2, Color::black()));

    vector<Light *> lights = vector<Light *>(0);
    lights.push_back(new DirectionLight(Vector3(0, -5, 0).normalize(), Color(1, 1, 1, 1), 0.2, 1, 32));
//    lights.push_back(new PointLight(Vector3(-10, 5, -10), Color(0, 1, 0, 1), 0.2, 1, 32));
//    lights.push_back(new PointLight(Vector3(0, 5, -10), Color(0, 0, 1, 1), 0.2, 1, 32));

    Scene *scene = new Scene(models, lights, camera, width, height);

    while (!device->windowShouldClose()) {

        scene->renderScene(device, 3);

        device->updateRender();

    }

    device->destory();

    for (auto &model : models) {
        if (model) {
            delete model;
            model = 0;
        }
    }
    for (auto &light : lights) {
        if (light) {
            delete light;
            light = 0;
        }
    }

    delete camera;
    delete scene;

    return 0;
}