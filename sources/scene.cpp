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
    this->screenWidth = 0;
    this->screenHeight = 0;
}

Scene::Scene(const std::vector<Sphere *> &models, std::vector<Plane *> planes, Camera *camera,
             DirectionLight *directionLight,
             const int &screenWidth,
             const int &screenHeight) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->camera = camera;
    this->spheres = models;
    this->planes = planes;
    this->directionLight = directionLight;
}

Scene::~Scene() {
}

Scene &Scene::operator=(const Scene &scene) {
    this->spheres = std::move(scene.spheres);
    this->camera = std::move(scene.camera);
    this->planes = std::move(scene.planes);
    this->screenWidth = scene.screenWidth;
    this->screenHeight = scene.screenHeight;
    return *this;
}

void Scene::renderScene(Device *device, int maxReflect) {

    this->maxReflect = maxReflect;

    Ray ray;
    for (int i = 0; i < screenWidth; ++i) {
        float sx = i / (float) screenWidth;
        for (int j = 0; j < screenHeight; ++j) {
            float sy = 1 - j / (float) screenHeight;
            ray = this->camera->generateRay(sx, sy);
            Color pixelColor = this->rayTrace(ray, maxReflect);
            device->setPixelColor(i, j, pixelColor);
        }
    }
}

Color Scene::rayTrace(const Ray &ray, float maxReflect) {
    IntersectResult tmpItRet, itRet;

    itRet.distance = maxReflect == this->maxReflect ? this->camera->far : INT_MAX;

    for (auto &sphere : this->spheres) {
        tmpItRet = Intersect::intersect(ray, *sphere);
        if (tmpItRet.isHit && tmpItRet.distance < itRet.distance) {
            itRet = tmpItRet;
        }
    }

    for (auto &plane : this->planes) {
        tmpItRet = Intersect::intersect(ray, *plane);
        if (tmpItRet.isHit && tmpItRet.distance < itRet.distance) {
            itRet = tmpItRet;
        }
    }


    if (itRet.geometry == NOGEO) return Color::black();
    float reflectiveness = Material::getReflectiveness(itRet.geometry);
    Color thisColor = directionLight->sample(ray, itRet).modulate() * (1 - reflectiveness) *
                      Material::getColor(itRet.geometry, itRet.position);

    if (maxReflect > 0 && reflectiveness > 0) {
        Ray reflectRay = Ray(itRet.position,
                             ray.direction - itRet.normal * (Vector3::dot(ray.direction, itRet.normal)) * 2);
        thisColor = thisColor + rayTrace(reflectRay, maxReflect - 1) * reflectiveness;
    }

    return thisColor;
}

