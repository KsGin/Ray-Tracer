/*
 * File   : Light
 * Author : KsGin 
 * Date   : 2018/6/12
 */

#include "../headers/light.h"

using namespace Math;

LightMaterial::LightMaterial() {

}

LightMaterial::~LightMaterial() {

}

DirectionLight::DirectionLight() {

}

DirectionLight::~DirectionLight() {

}

DirectionLight::DirectionLight(const Math::Vector3 &direction, const Color &color, float diffuse, float specular,
                               float shininess) {
    this->direction = direction;
    this->color = color;
    this->diffuse = diffuse;
    this->shininess = shininess;
    this->specular = specular;
}

DirectionLight::DirectionLight(const DirectionLight &dLight) {
    this->direction = dLight.direction;
    this->color = dLight.color;
    this->diffuse = dLight.diffuse;
    this->specular = dLight.specular;
    this->shininess = dLight.shininess;
}

DirectionLight &DirectionLight::operator=(const DirectionLight &dLight) {
    this->direction = dLight.direction;
    this->color = dLight.color;
    this->shininess = dLight.shininess;
    this->specular = dLight.specular;
    this->diffuse = dLight.diffuse;
    return *this;
}

Color DirectionLight::sample(const Ray &ray, const IntersectResult &itRet) {
    float NdotL = Vector3::dot(this->direction, itRet.normal);
    float NdotH = Vector3::dot((this->direction - ray.direction).normalize(), itRet.normal);
    float diffuseIntensity = this->diffuse * NdotL > 0 ? NdotL : 0;
    float specularIntensity = this->specular * pow(NdotH > 0 ? NdotH : 0, this->shininess);
    return this->color * (diffuseIntensity + specularIntensity);
}


