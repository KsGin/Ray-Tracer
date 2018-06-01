/*
 * File   : camera
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#include "../headers/camera.h"

using namespace Math;

PerspectiveCamera::PerspectiveCamera() {

}

PerspectiveCamera::PerspectiveCamera(float fov, const Math::Vector3 &eye, const Math::Vector3 &front,
                                     const Math::Vector3 &up) {
    this->eye = eye;
    this->front = front;
    this->right = Vector3::cross(front, up);
    this->up = Vector3::cross(right, front);
    this->fovScale = static_cast<float>(tan(fov * 0.5 * M_PI / 180) * 2);
}

Ray PerspectiveCamera::generateRay(float x, float y) {
    Vector3 right = this->right.scale(static_cast<float>((x - 0.5) * this->fovScale),
                                      static_cast<float>((x - 0.5) * this->fovScale),
                                      static_cast<float>((x - 0.5) * this->fovScale));

    Vector3 up = this->up.scale(static_cast<float>((y - 0.5) * this->fovScale),
                                static_cast<float>((y - 0.5) * this->fovScale),
                                static_cast<float>((y - 0.5) * this->fovScale));
    return Ray(eye, (front + right + up).normalize());
}
