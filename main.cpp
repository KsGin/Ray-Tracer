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
const float sphereRefractiveness = 0;
const float sphereReflectiveness = 0.2;
const float planeRefractiveness = 0;
const float planeReflectiveness = 0.2;

int main() {

    Device *device = new Device();

    device->initialize(width, height, isScreenFull);

    Camera *camera = new PerspectiveCamera(90, Vector3(0, 10, -10), Vector3(0, 0, 0), Vector3(0, 1, 0), 0.01, 50);

    vector<Model *> models = vector<Model *>(0);
    models.push_back(new Sphere(Vector3(0, 2, 0), 2, sphereReflectiveness, sphereRefractiveness, Color::red()));
    models.push_back(new Sphere(Vector3(5, 2, -2), 2, sphereReflectiveness, sphereRefractiveness, Color::green()));
    models.push_back(new Sphere(Vector3(-5, 2, -2), 2, sphereReflectiveness, sphereRefractiveness, Color::blue()));
    models.push_back(new Plane(Vector3(0, 1, 0), 0, planeReflectiveness, planeRefractiveness, Color::white()));
    models.push_back(new Plane(Vector3(0, 0, -1), -10, planeReflectiveness, planeRefractiveness, Color::white()));
    models.push_back(new Plane(Vector3(1, 0, 0), -10, planeReflectiveness, planeRefractiveness, Color::white()));
    models.push_back(new Plane(Vector3(-1, 0, 0), -10, planeReflectiveness, planeRefractiveness, Color::white()));

    vector<Light *> lights = vector<Light *>(0);
    lights.push_back(new AmbientLight(0.05));
//    lights.push_back(new DirectionLight(Vector3(5, -5, 0).normalize(), Color(1, 1, 1, 1), 0.9, 1, 64));
    lights.push_back(new PointLight(Vector3(-5, 5, -5), Color(1, 0.2, 0.2, 1), 0.3, 1, 64, 50));
    lights.push_back(new PointLight(Vector3(5, 5, -5), Color(0.2, 0.2, 1, 1), 0.3, 1, 64, 50));
//    lights.push_back(new PointLight(Vector3(0, 5, -5), Color(0.2, 1, 0.2, 1), 0.3, 1, 64, 50));

    Scene *scene = new Scene(models, lights, camera, width, height);

    // 渲染
    scene->renderScene(device, 3);
    device->updateRender();

    // 显示
    device->show();

    while (!device->windowShouldClose()) {
        device->handleEvent();
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