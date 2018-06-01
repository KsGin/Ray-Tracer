/*
 * File   : ray
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#include "../headers/ray.h"

using namespace Math;

Ray::Ray() {
    this->origin = Vector3(0, 0, 0);
    this->direction = Vector3(0, 0, -1);
}

Ray::Ray(const Math::Vector3 &origin, const Math::Vector3 &direction) {
    this->origin = origin;
    this->direction = direction;
}

Ray::Ray(const Ray &r) {
    this->origin = r.origin;
    this->direction = r.direction;
}

Ray &Ray::operator=(const Ray &r) {
    this->direction = r.direction;
    this->origin = r.origin;
    return *this;
}
