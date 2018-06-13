/*
 * File   : sphere
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#include "../headers/sphere.h"

using namespace Math;

Sphere::Sphere() {
    this->radius = 0;
}

Sphere::Sphere(const Math::Vector3 &center, const float &radius) {
    this->center = center;
    this->radius = radius;
}

Sphere::Sphere(const Sphere &s) {
    this->center = s.center;
    this->radius = s.radius;
}

Sphere &Sphere::operator=(const Sphere &s) {
    this->center = s.center;
    this->radius = s.radius;
    return *this;
}
