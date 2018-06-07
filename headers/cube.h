/*
 * File   : cube
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#ifndef RAY_TRACER_CUBE_H
#define RAY_TRACER_CUBE_H

#include "../include/math/vector.hpp"

/*
 * Cube 类
 */
class Cube {
public:
    /*
     * 中心坐标
     */
    Math::Vector3 center;
    /*
     * 半径
     */
    float radius;

    /*
     * 空构造方法
     */
    Cube();

    /*
     * 值赋值构造方法
     */
    Cube(const Math::Vector3 &center, const float &radius);

    /*
     * 对象拷贝构造方法
     */
    Cube(const Cube &s);

    /*
     * 重载 =
     */
    Cube &operator=(const Cube &s);
};


#endif //RAY_TRACER_CUBE_H
