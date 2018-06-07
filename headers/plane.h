/*
 * File   : plane
 * Author : KsGin
 * Date   : 2018/6/7
 */

#ifndef RAY_TRACER_PLANE_H
#define RAY_TRACER_PLANE_H

#include "../include/math/vector.hpp"

/*
 * 平面类
 */
class Plane {
public:
    /*
     * 平面法线
     */
    Math::Vector3 normal;
    /*
     * 到原点距离
     */
    float distance;

    /*
     * 空构造方法
     */
    Plane();

    /*
     * 空析构方法
     */
    ~Plane();

    /*
     * 赋值构造方法
     */
    Plane(const Math::Vector3& normal , const float distance);

    /*
     * 对象拷贝
     */
    Plane(const Plane& plane);

    /*
     * 重载 =
     */
    Plane &operator=(const Plane& plane);
};


#endif //RAY_TRACER_PLANE_H
