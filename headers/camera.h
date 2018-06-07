/*
 * File   : camera
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#ifndef RAY_TRACER_CAMERA_H
#define RAY_TRACER_CAMERA_H

#include "../include/math/vector.hpp"
#include "ray.h"

/*
 * 摄像机类基类
 */
class Camera {
public:
    virtual ~Camera();
    /*
     * 定义虚函数
     */
    virtual Ray generateRay(float x, float y) = 0;
};

/*
 * 透视投影摄像机
 */
class PerspectiveCamera : public Camera {
    /*
     * 缩放
     */
    float fovScale;
    /*
     * eye 坐标
     */
    Math::Vector3 eye;
    /*
     * 方向向量 up
     */
    Math::Vector3 up;
    /*
     * 方向向量 right
     */
    Math::Vector3 right;
    /*
     * 方向向量 front
     */
    Math::Vector3 front;

    /*
     * 空构造方法
     */
    PerspectiveCamera();

public:
    /*
     * 构造方法
     */
    PerspectiveCamera(float fov, const Math::Vector3 &eye, const Math::Vector3 &lookAt, const Math::Vector3 &up);

    /*
     * 析构方法
     */
    ~PerspectiveCamera();

    /*
     * 根据 x y 位置生成光线
     */
    Ray generateRay(float x, float y);
};

/*
 * 正交投影摄像机
 */
class OrthoCamera : public Camera {

};


#endif //RAY_TRACER_CAMERA_H
