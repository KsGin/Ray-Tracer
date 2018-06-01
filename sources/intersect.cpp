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
    return ret;
}
