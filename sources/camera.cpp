/*
 * File   : camera
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#include "../headers/camera.h"

using namespace Math;

PerspectiveCamera::PerspectiveCamera() {

}

PerspectiveCamera::PerspectiveCamera(float fov, const Math::Vector3 &eye, const Math::Vector3 &lookAt,
                                     const Math::Vector3 &up) {
    this->eye = eye;
    this->front = (lookAt - this->eye).normalize();
    this->right = Vector3::cross(front, up).normalize();
    this->up = Vector3::cross(right, front).normalize();
    this->fovScale = static_cast<float>(tan(fov * 0.5 * M_PI / 180) * 2);
}

Ray PerspectiveCamera::generateRay(float x, float y) {

    float scaleX = static_cast<float>((x - 0.5) * this->fovScale);
    Vector3 r = this->right * scaleX;

    float scaleY = static_cast<float>((y - 0.5) * this->fovScale);
    Vector3 u = this->up * scaleY;

    return Ray(eye, (front + r + u).normalize());
}
