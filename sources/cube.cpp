/*
 * File   : cube
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#include "../headers/cube.h"

using namespace Math;

Cube::Cube() {
    this->center = Vector3(0, 0, 0);
    this->radius = 0;
}

Cube::Cube(const Math::Vector3 &center, const float &radius) {
    this->center = center;
    this->radius = radius;
}

Cube::Cube(const Cube &s) {
    this->center = s.center;
    this->radius = s.radius;
}

Cube &Cube::operator=(const Cube &s) {
    this->center = s.center;
    this->radius = s.radius;
    return *this;
}
