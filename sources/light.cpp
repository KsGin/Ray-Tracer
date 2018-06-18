/*
 * File   : Light
 * Author : KsGin 
 * Date   : 2018/6/12
 */

#include "../headers/light.h"

using namespace Math;

Light::Light() {

}

Light::~Light() {

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

Color DirectionLight::sample(const Ray &ray, const IntersectResult &itRet, const std::vector<Model *> models) {
    Vector3 negateLightDirection = Vector3(this->direction).negate();

    // 处理阴影
    Ray shadowRay = Ray(itRet.position, negateLightDirection);
    IntersectResult tmpItRet;
    for (auto &model : models) {
        tmpItRet = model->intersect(shadowRay);
        if (tmpItRet.isHit) {
            return Color::black();
        }
    }

    float NdotL = Vector3::dot(negateLightDirection, itRet.normal);
    float NdotH = Vector3::dot((negateLightDirection - ray.direction).normalize(), itRet.normal);
    float diffuseIntensity = this->diffuse * (NdotL > 0 ? NdotL : 0);
    float specularIntensity = this->specular * pow(NdotH > 0 ? NdotH : 0, this->shininess);
    return this->color * (diffuseIntensity + specularIntensity);
}


PointLight::PointLight(const Vector3 &position, const Color &color, float diffuse, float specular, float shininess,
                       float far) {
    this->position = position;
    this->color = color;
    this->shininess = shininess;
    this->specular = specular;
    this->diffuse = diffuse;
    this->far = far;
}

PointLight::PointLight(const PointLight &pLight) {
    this->position = pLight.position;
    this->color = pLight.color;
    this->shininess = pLight.shininess;
    this->specular = pLight.specular;
    this->diffuse = pLight.diffuse;
    this->far = pLight.far;
}

PointLight &PointLight::operator=(const PointLight &pLight) {
    this->position = pLight.position;
    this->color = pLight.color;
    this->shininess = pLight.shininess;
    this->specular = pLight.specular;
    this->diffuse = pLight.diffuse;
    this->far = pLight.far;
    return *this;
}

Color PointLight::sample(const Ray &ray, const IntersectResult &itRet, const std::vector<Model *> models) {
    Vector3 delta = this->position - itRet.position;
    float r = delta.length();
    float attenuation = 1 / (r * r) * this->far;
    Vector3 lightDirection = delta.normalize();

    // 处理阴影
    Ray shadowRay = Ray(itRet.position, lightDirection);
    IntersectResult tmpItRet;
    for (auto &model : models) {
        tmpItRet = model->intersect(shadowRay);
        if (tmpItRet.isHit && tmpItRet.distance < r) {
            return Color::black();
        }
    }

    float NdotL = Vector3::dot(lightDirection, itRet.normal);
    float NdotH = Vector3::dot((lightDirection - ray.direction).normalize(), itRet.normal);
    float diffuseIntensity = this->diffuse * (NdotL > 0 ? NdotL : 0);
    float specularIntensity = this->specular * pow(NdotH > 0 ? NdotH : 0, this->shininess);

    return this->color * (diffuseIntensity + specularIntensity) * attenuation;
}

AmbientLight::AmbientLight() {
    this->ambientIntensity = 0;
}

AmbientLight::~AmbientLight() {

}

AmbientLight::AmbientLight(float ambientIntensity) {
    this->ambientIntensity = ambientIntensity;
}

Color AmbientLight::sample(const Ray &ray, const IntersectResult &itRet, const std::vector<Model *> models) {
    return Color::white() * this->ambientIntensity;
}

AmbientLight::AmbientLight(const AmbientLight &ambientLight) {
    this->ambientIntensity = ambientLight.ambientIntensity;
}

AmbientLight &AmbientLight::operator=(const AmbientLight &ambientLight) {
    this->ambientIntensity = ambientLight.ambientIntensity;
    return *this;
}
