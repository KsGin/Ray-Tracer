/*
 * File   : model
 * Author : KsGin 
 * Date   : 2018/6/14
 */

#include "../headers/model.h"

using namespace Math;

Plane::Plane() {
    this->distance = 0;
}

Plane::~Plane() {

}

Plane::Plane(const Math::Vector3 &normal, const float &distance,
             const float &reflectiveness, const float &refractiveness, const float &transparency,
             const Color &color) {
    this->normal = normal;
    this->distance = distance;
    this->color = color;
    this->reflectiveness = reflectiveness;
    this->refractiveness = refractiveness;
    this->transparency = transparency;
}

Plane::Plane(const Plane &plane) {
    this->normal = plane.normal;
    this->distance = plane.distance;
    this->reflectiveness = plane.reflectiveness;
    this->refractiveness = plane.refractiveness;
    this->transparency = plane.transparency;
    this->color - plane.color;
}

Plane &Plane::operator=(const Plane &plane) {
    this->normal = plane.normal;
    this->distance = plane.distance;
    this->reflectiveness = plane.reflectiveness;
    this->refractiveness = plane.refractiveness;
    this->transparency = plane.transparency;
    this->color - plane.color;
    return *this;
}

IntersectResult Plane::intersect(const Ray &ray) {
    IntersectResult ret;
    float dt = Vector3::dot(ray.direction, this->normal);
    if (dt < 0) {
        float db = Vector3::dot(this->normal, ray.origin - (this->normal * this->distance));
        ret.isHit = true;
        ret.geometry = PLANE;
        ret.normal = this->normal;
        ret.distance = -db / dt;
        ret.position = ray.origin + (ray.direction * ret.distance);
    }
    return ret;
}

float Plane::getReflectiveness() {
    return this->reflectiveness;
}

Color Plane::getColor(const IntersectResult &itRet) {
    float u = 0, v = 0;
    if (itRet.normal._x != 0) {
        u = itRet.position._y;
        v = itRet.position._z;
    }
    if (itRet.normal._y != 0) {
        u = itRet.position._x;
        v = itRet.position._z;
    }
    if (itRet.normal._z != 0) {
        u = itRet.position._x;
        v = itRet.position._y;
    }
    return abs(static_cast<int>(
               floor(u * 0.5) +
               floor(v * 0.5)) % 2) < 1 ?
           Color::white() : Color::black();
}

float Plane::getRefractiveness() {
    return this->refractiveness;
}

float Plane::getTransparency() {
    return this->transparency;
}


Sphere::Sphere() {
    this->radius = 0;
}

Sphere::Sphere(const Math::Vector3 &center, const float &radius,
               const float &reflectiveness, const float &refractiveness, const float &transparency,
               const Color &color) {
    this->center = center;
    this->radius = radius;
    this->reflectiveness = reflectiveness;
    this->refractiveness = refractiveness;
    this->transparency = transparency;
    this->color = color;
}

Sphere::Sphere(const Sphere &s) {
    this->center = s.center;
    this->radius = s.radius;
    this->reflectiveness = s.reflectiveness;
    this->refractiveness = s.refractiveness;
    this->color = s.color;
}

Sphere &Sphere::operator=(const Sphere &s) {
    this->center = s.center;
    this->radius = s.radius;
    this->reflectiveness = s.reflectiveness;
    this->refractiveness = s.refractiveness;
    this->transparency = s.transparency;
    this->color = s.color;
    return *this;
}

IntersectResult Sphere::intersect(const Ray &ray) {
    IntersectResult ret;

    Vector3 v = ray.origin - this->center;     // v = origin - center
    float rayLength = v.length();
    float d = rayLength * rayLength - this->radius * this->radius;       // d = v * v - radius * radius
    float dotV = Vector3::dot(ray.direction, v);

    if (dotV <= 0) {
        float discr = dotV * dotV - d;
        if (discr >= 0) {
            ret.isHit = true;
            ret.geometry = SPHERE;
            ret.distance = -dotV - sqrt(discr);
            ret.position = ray.origin + (ray.direction * ret.distance);
            ret.normal = (ret.position - this->center).normalize();
        }
    }

    return ret;
}

float Sphere::getReflectiveness() {
    return this->reflectiveness;
}

Color Sphere::getColor(const IntersectResult &itRet) {
    return this->color;
}

float Sphere::getRefractiveness() {
    return this->refractiveness;
}

float Sphere::getTransparency() {
    return this->transparency;
}

IntersectResult::IntersectResult() {
    this->geometry = NOGEO;
    this->distance = 0;
    this->isHit = false;
}

IntersectResult::IntersectResult(const IntersectResult &result) {
    this->distance = result.distance;
    this->isHit = result.isHit;
    this->normal = result.normal;
    this->position = result.position;
    this->geometry = result.geometry;
}

IntersectResult &IntersectResult::operator=(const IntersectResult &result) {
    this->geometry = result.geometry;
    this->position = result.position;
    this->normal = result.normal;
    this->isHit = result.isHit;
    this->distance = result.distance;
    return *this;
}

Model::~Model() {

}