/*
 * File   : scene
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#include <iostream>
#include "../headers/scene.h"
#include "../headers/intersect.h"
#include "../headers/color.h"
#include "../include/math/vector.hpp"

using namespace Math;

Scene::Scene() {
    this->directionLight = 0;
    this->camera = 0;
    this->plane = 0;
    this->screenWidth = 0;
    this->screenHeight = 0;
}

Scene::Scene(const std::vector<Sphere *> &models, Camera *camera, Plane *plane, DirectionLight *directionLight,
             const int &screenWidth,
             const int &screenHeight) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->camera = camera;
    this->spheres = models;
    this->plane = plane;
    this->directionLight = directionLight;
}

Scene::~Scene() {
}

Scene &Scene::operator=(const Scene &scene) {
    this->spheres = std::move(scene.spheres);
    this->camera = std::move(scene.camera);
    this->screenWidth = scene.screenWidth;
    this->screenHeight = scene.screenHeight;
    return *this;
}

void Scene::RenderScene(Device *device, int maxReflect) {
    IntersectResult itRet;
    Ray ray;
    float minDistance;
    for (int i = 0; i < screenWidth; ++i) {
        float sx = i / (float) screenWidth;
        for (int j = 0; j < screenHeight; ++j) {
            float sy = 1 - j / (float) screenHeight;

            minDistance = camera->far;   // 距离超过远平面不可见

            ray = this->camera->generateRay(sx, sy);
            for (auto &sphere : this->spheres) {
                itRet = Intersect::intersect(ray, *sphere);
                if (itRet.isHit && itRet.distance < minDistance && itRet.distance > camera->near) {
                    minDistance = itRet.distance;
                    device->setPixelColor(i, j, directionLight->sample(ray, itRet));
                }
            }

            itRet = Intersect::intersect(ray, *plane);
            if (itRet.isHit && itRet.distance <= minDistance && itRet.distance > camera->near) {
                Color lightColor = directionLight->sample(ray, itRet);
                Color textureColor = abs(static_cast<int>(
                                         floor(itRet.position._x * 0.5) +
                                         floor(itRet.position._z * 0.5)) % 2) < 1 ?
                                     Color::white() : Color::black();
                device->setPixelColor(i, j, (lightColor * textureColor).modulate());
            }

        }
    }
}

