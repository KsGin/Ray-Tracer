/*
 * File   : scene
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#include <iostream>
#include "../headers/scene.h"
#include "../headers/color.h"
#include "../include/math/vector.hpp"
#include "../headers/model.h"

using namespace Math;

Scene::Scene() {
    this->camera = 0;
    this->screenWidth = 0;
    this->screenHeight = 0;
}

Scene::Scene(const std::vector<Model *> &models,
             const std::vector<Light *> &lights,
             Camera *camera,
             const int &screenWidth,
             const int &screenHeight) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->camera = camera;
    this->models = models;
    this->lights = lights;
}

Scene::~Scene() {
}

Scene &Scene::operator=(const Scene &scene) {
    this->camera = std::move(scene.camera);
    this->models = std::move(scene.models);
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

    int idx = 0, cut = idx;
    for (auto &model : this->models) {
        tmpItRet = model->intersect(ray);
        if (tmpItRet.isHit && tmpItRet.distance < itRet.distance) {
            itRet = tmpItRet;
            cut = idx;
        }
        idx++;
    }

    if (itRet.geometry == NOGEO) return Color::black();

    float reflectiveness = models[cut]->getReflectiveness();
    Color thisColor = models[cut]->getColor(itRet) * (1 - reflectiveness);

    Color lightColor = Color::black();

    for (auto &light : this->lights) {
        lightColor = (lightColor + light->sample(ray, itRet)).modulate();
    }

    thisColor = thisColor * lightColor;

    if (maxReflect > 0 && reflectiveness > 0) {
        Ray reflectRay = Ray(itRet.position,
                             ray.direction - itRet.normal * (Vector3::dot(ray.direction, itRet.normal)) * 2);
        thisColor = thisColor + rayTrace(reflectRay, maxReflect - 1) * reflectiveness;
    }

    return thisColor;
}

