/*
 * File   : plane
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#include "../headers/plane.h"

Plane::Plane() {
    this->distance = 0;
}

Plane::~Plane() {

}

Plane::Plane(const Math::Vector3 &normal, const float distance) {
    this->normal = normal;
    this->distance = distance;
}

Plane::Plane(const Plane &plane) {
    this->normal = plane.normal;
    this->distance = plane.distance;
}

Plane &Plane::operator=(const Plane &plane) {
    this->normal = plane.normal;
    this->distance = plane.distance;
    return *this;
}


