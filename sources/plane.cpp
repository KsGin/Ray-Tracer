/*
 * File   : plane
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#include "../headers/plane.h"

Plane::Plane() {
    this->distance = 0;
    this->reflectiveness = 0;
}

Plane::~Plane() {

}

Plane::Plane(const Math::Vector3 &normal, const float &distance, const float &reflectiveness) {
    this->normal = normal;
    this->distance = distance;
    this->reflectiveness = reflectiveness;
}

Plane::Plane(const Plane &plane) {
    this->normal = plane.normal;
    this->distance = plane.distance;
    this->reflectiveness = plane.reflectiveness;
}

Plane &Plane::operator=(const Plane &plane) {
    this->normal = plane.normal;
    this->distance = plane.distance;
    this->reflectiveness = reflectiveness;
    return *this;
}


