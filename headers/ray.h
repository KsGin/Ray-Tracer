/*
 * File   : ray
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#ifndef RAY_TRACER_RAY_H
#define RAY_TRACER_RAY_H

#include "../include/math/vector.hpp"

/*
 * 光线类
 */
class Ray {

public:
    /*
     * 光线起点 origin
     */
    Math::Vector3 origin;
    /*
     * 光线方向 direction
     */
    Math::Vector3 direction;

    /*
     * 空构造方法
     */
    Ray();

    /*
     * 值拷贝构造方法
     */
    Ray(const Math::Vector3 &origin, const Math::Vector3 &direction);

    /*
     * 对象拷贝构造方法
     */
    Ray(const Ray &r);

    /*
     * 重载 =
     */
    Ray &operator=(const Ray &r);
};


#endif //RAY_TRACER_RAY_H
