/*
 * File   : Light
 * Author : KsGin
 * Date   : 2018/6/12
 */

#ifndef RAY_TRACER_LIGHT_H
#define RAY_TRACER_LIGHT_H

#include "../include/math/vector.hpp"
#include "color.h"
#include "ray.h"
#include "intersect.h"

/*
 * 光线材质
 */
class LightMaterial {
public:
    /*
     * 漫反射
     */
    float diffuse;
    /*
     * 镜面反射
     */
    float specular;
    /*
     * 亮度
     */
    float shininess;

    /*
     * 空构造
     */
    LightMaterial();

    virtual /*
     * 空析构
     */
    ~LightMaterial();

    /*
     * 采样方法
     */
    virtual Color sample(const Ray& ray , const IntersectResult& itRet) = 0;
};

/*
 * 平行光
 */
class DirectionLight : public LightMaterial {
public:
    /*
     * 光线方向
     */
    Math::Vector3 direction;
    /*
     * 光线颜色
     */
    Color color;

    /*
     * 空构造方法
     */
    DirectionLight();

    /*
     * 空析构方法
     */
    ~DirectionLight();

    /*
     * 值构造
     */
    DirectionLight(const Math::Vector3 &direction, const Color &color, float diffuse, float specular, float shininess);

    /*
     * 对象构造
     */
    DirectionLight(const DirectionLight &dLight);

    /*
     * 重载 =
     */
    DirectionLight &operator=(const DirectionLight &dLight);

    /*
     * 颜色取样
     */
    Color sample(const Ray& ray , const IntersectResult& itRet);
};


#endif //RAY_TRACER_LIGHT_H
