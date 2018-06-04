/*
 * File   : sphere
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H

#include "../include/math/vector.hpp"

/*
 * 球体类
 */
class Sphere {
public:

    /*
     * 球心坐标
     */
    Math::Vector3 center;

    /*
     * 球半径
     */
    float radius;

    /*
     * 空构造方法
     */
    Sphere();

    /*
     * 值赋值构造方法
     */
    Sphere(const Math::Vector3 &center, const float &radius);

    /*
     * 对象拷贝构造方法
     */
    Sphere(const Sphere &s);

    /*
     * 重载 =
     */
    Sphere &operator=(const Sphere &s);
};


#endif //RAY_TRACER_SPHERE_H
