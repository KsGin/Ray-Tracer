/*
 * File   : scene
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#include "../headers/scene.h"
#include "../headers/intersect.h"
#include "../headers/color.h"
#include "../include/math/vector.hpp"

using namespace Math;

Scene::Scene() {
    this->camera = 0;
    this->plane = 0;
    this->screenWidth = 0;
    this->screenHeight = 0;
}

Scene::Scene(const std::vector<Sphere *> &models, Camera *camera, Plane *plane, const int &screenWidth,
             const int &screenHeight) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->camera = camera;
    this->spheres = models;
    this->plane = plane;
}

Scene::~Scene() {
    if (!this->spheres.empty()) {
        for (auto sphere : this->spheres) {
            if (sphere) {
                delete sphere;
                sphere = 0;
            }
        }
    }
    if (this->camera) {
        delete this->camera;
        this->camera = 0;
    }
    if (this->plane) {
        delete this->plane;
        this->plane = 0;
    }
}

Scene &Scene::operator=(const Scene &scene) {
    this->spheres = std::move(scene.spheres);
    this->camera = std::move(scene.camera);
    this->screenWidth = scene.screenWidth;
    this->screenHeight = scene.screenHeight;
    return *this;
}

void Scene::RenderScene(Device *device) {
    IntersectResult itRet;
    Ray ray;
    for (int i = 0; i < screenWidth; ++i) {
        float sx = i / (float) screenWidth;
        for (int j = 0; j < screenHeight; ++j) {
            float sy = j / (float) screenHeight;
            ray = this->camera->generateRay(sx, sy);

            itRet = Intersect::intersect(ray, *plane);
            if (itRet.isHit) {
                device->setPixelColor(i, j, Color(1, 1, 1, 1));
            }

            for (auto &sphere : this->spheres) {
                itRet = Intersect::intersect(ray, *sphere);
                if (itRet.isHit) {
                    device->setPixelColor(i, j, Color(itRet.nromal._x, itRet.nromal._y, itRet.nromal._z, 1));
                }
            }
        }
    }
}

