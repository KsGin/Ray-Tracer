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

    // 获得折射度和反射度以及透明度
    float reflectiveness = models[cut]->getReflectiveness();
    float refractiveness = models[cut]->getRefractiveness();
    float transparency = models[cut]->getTransparency();

    // 最终颜色
    Color finalColor = Color::black();

    // 计算光照颜色
    Color lightColor = Color::black();
    for (auto &light : this->lights) {
        lightColor = lightColor + light->sample(ray, itRet, this->models);
    }

    // 取得材质颜色
    Color materialColor = models[cut]->getColor(itRet);

    // 递归追踪计算反射颜色
    Color reflectionColor = Color::black();
    if (maxReflect > 0 && reflectiveness > 0) {
        Vector3 reflectDirection = ray.direction - itRet.normal * (Vector3::dot(ray.direction, itRet.normal)) * 2;
        Ray reflectRay = Ray(itRet.position, reflectDirection);
        reflectionColor = reflectionColor + rayTrace(reflectRay, maxReflect - 1);
    }

    // 递归追踪计算折射颜色 problem1
    Color refractionColor = Color::black();
    if (maxReflect > 0 && transparency > 0) {
        Vector3 refractDirection = (ray.direction + Vector3(refractiveness, 0, 0)).normalize();
        Ray refractRay = Ray(itRet.position, refractDirection);
        itRet = models[cut]->intersect(refractRay);
        refractionColor = rayTrace(refractRay, maxReflect - 1);
    }

    // 混合
    finalColor = materialColor * lightColor * Device::clamp(1 - reflectiveness) +
                 reflectionColor * Device::clamp(1 - transparency) +
                 refractionColor * Device::clamp(transparency);

    return finalColor;
}

