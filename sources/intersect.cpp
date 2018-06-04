/*
 * File   : intersect
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#include "../headers/Intersect.h"

using namespace Math;

IntersectResult::IntersectResult() {
    this->geometry = NOGEO;
    this->distance = 0;
    this->isHit = false;
}

IntersectResult::IntersectResult(const IntersectResult &result) {
    this->distance = result.distance;
    this->isHit = result.isHit;
    this->nromal = result.nromal;
    this->position = result.position;
    this->geometry = result.geometry;
}

IntersectResult &IntersectResult::operator=(const IntersectResult &result) {
    this->geometry = result.geometry;
    this->position = result.position;
    this->nromal = result.nromal;
    this->isHit = result.isHit;
    this->distance = result.distance;
    return *this;
}

IntersectResult Intersect::intersect(const Ray &ray, const Sphere &sphere) {
    IntersectResult ret;

    Vector3 v = ray.origin - sphere.center;
    float d = v.length() - sphere.radius;
    float dotV = Vector3::dot(ray.direction, v);

    if (dotV <= 0) {
        float discr = dotV * dotV - d;
        if (discr >= 0) {
            ret.geometry = SPHERE;
            ret.distance = -dotV - sqrt(discr);
            ret.position = ray.origin + ray.direction.scale(ret.distance, ret.distance, ret.distance);
            ret.nromal = (ret.position - sphere.center).normalize();
        }
    }

    return ret;
}
