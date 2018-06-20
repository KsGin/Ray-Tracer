/*
 * File   : model
 * Author : KsGin 
 * Date   : 2018/6/14
 */

#ifndef RAY_TRACER_MODEL_H
#define RAY_TRACER_MODEL_H

#include "../include/math/vector.hpp"
#include "color.h"
#include "ray.h"

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
     * 平面
     */
    PLANE = 2
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
 * 模型类
 */
class Model {
public:

    /*
     * 反射度
     */
    float reflectiveness;

    /*
     * 折射度
     */
    float refractiveness;

    /*
     * 透明度
     */
    float transparency;

    /*
     * 颜色
     */
    Color color;

    /*
     * 虚析构方法
     */
    virtual ~Model();

    /*
     * 虚函数 相交测试
     */
    virtual IntersectResult intersect(const Ray &ray) = 0;

    /*
     * 虚函数 内部相交测试
     */
    virtual IntersectResult innerIntersect(const Ray &ray) = 0;

    /*
     * 获得模型反射度
     */
    virtual float getReflectiveness() = 0;

    /*
     * 获得模型反射度
     */
    virtual float getRefractiveness() = 0;

    /*
     * 获得透明度
     */
    virtual float getTransparency() = 0;

    /*
     * 获得交点颜色
     */
    virtual Color getColor(const IntersectResult &itRet) = 0;
};

/*
 * 平面类
 */
class Plane : public Model {
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
    Plane(const Math::Vector3 &normal, const float &distance,
          const float &reflectiveness, const float &refractiveness, const float &transparency,
          const Color &color);

    /*
     * 对象拷贝
     */
    Plane(const Plane &plane);

    /*
     * 重载 =
     */
    Plane &operator=(const Plane &plane);

    /*
     * 相交测试
     */
    IntersectResult intersect(const Ray &ray);

    /*
     * 内部相交测试
     */
    IntersectResult innerIntersect(const Ray &ray);

    /*
     * 获得交点反射度
    */
    float getReflectiveness();

    /*
     * 获得交点折射度
    */
    float getRefractiveness();

    /*
     * 获得透明度
     */
    float getTransparency();

    /*
     * 获得颜色
     */
    Color getColor(const IntersectResult &itRet);
};


/*
 * 球体类
 */
class Sphere : public Model {
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
    Sphere(const Math::Vector3 &center, const float &radius,
           const float &reflectiveness, const float &refractiveness, const float &transparency,
           const Color &color);

    /*
     * 对象拷贝构造方法
     */
    Sphere(const Sphere &s);

    /*
     * 重载 =
     */
    Sphere &operator=(const Sphere &s);

    /*
     * 相交测试
     */
    IntersectResult intersect(const Ray &ray);

    /*
     * 内部相交测试
     */
    IntersectResult innerIntersect(const Ray &ray);

    /*
     * 获得交点反射度
     */
    float getReflectiveness();

    /*
     * 获得交点折射度
     */
    float getRefractiveness();

    /*
     * 获得透明度
     */
    float getTransparency();

    /*
     * 获得颜色
     */
    Color getColor(const IntersectResult &itRet);
};


#endif //RAY_TRACER_MODEL_H
