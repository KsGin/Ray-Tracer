/*
 * File   : intersect
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#ifndef RAY_TRACER_INTERSECT_H
#define RAY_TRACER_INTERSECT_H

#include "../include/math/vector.hpp"
#include "ray.h"
#include "sphere.h"
#include "cube.h"
#include "plane.h"

/*
 * 集合类型
 */
enum GEOMETRY {
    /*
     * 空
     */
    NOGEO = 0,
    /*
     * 球体
     */
    SPHERE = 1,
    /*
     * 立方体
     */
    CUBE = 2,
    /*
     * 平面
     */
    PLANE = 3
};

/*
 * 相交结果
 */
class IntersectResult {
public:
    /*
     * 是否击中
     */
    bool isHit;
    /*
     * 图元类型
     */
    GEOMETRY geometry;
    /*
     * 距离
     */
    float distance;
    /*
     * 击中位置
     */
    Math::Vector3 position;
    /*
     * 法线
     */
    Math::Vector3 normal;

public:
    /*
     * 空构造方法
     */
    IntersectResult();

    /*
     * 引用拷贝构造方法
     */
    IntersectResult(const IntersectResult &result);

    /*
     * 重载 =
     */
    IntersectResult &operator=(const IntersectResult &result);
};

/*
 * 相交类
 */
class Intersect {
public:

    /*
     * 球与光线相交
     */
    static IntersectResult intersect(const Ray &ray, const Sphere &sphere);


    /*
     * 立方体与光线相交
     */
    static IntersectResult intersect(const Ray &ray, const Cube &cube);

    /*
     * 平面与光线相交
     */
    static IntersectResult intersect(const Ray &ray, const Plane &plane);
};


#endif //RAY_TRACER_INTERSECT_H
