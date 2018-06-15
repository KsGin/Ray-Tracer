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
#include "model.h"

/*
 * 光线材质
 */
class Light {
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
     * 颜色
     */
    Color color;

    /*
     * 空构造
     */
    Light();

    /*
     * 空析构
     */
    virtual ~Light();

    /*
     * 采样方法
     */
    virtual Color sample(const Ray &ray, const IntersectResult &itRet) = 0;
};

/*
 * 平行光
 */
class DirectionLight : public Light {
public:
    /*
     * 光线方向
     */
    Math::Vector3 direction;

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
    Color sample(const Ray &ray, const IntersectResult &itRet);
};

/*
 * 点光源
 */

class PointLight : public Light {
public:
    /*
     * 点光源位置
     */
    Math::Vector3 position;

    /*
     * 最远辐射位置
     */
    float far;

    /*
     * 值构造
     */
    PointLight(const Math::Vector3 &position, const Color &color, float diffuse, float specular, float shininess,
               float far);

    /*
     * 对象构造
     */
    PointLight(const PointLight &pLight);

    /*
     * 重载 =
     */
    PointLight &operator=(const PointLight &pLight);

    /*
     * 颜色取样
     */
    Color sample(const Ray &ray, const IntersectResult &itRet);
};

/*
 * 环境光
 */
class AmbientLight : public Light {
public:
    /*
     * 环境光亮度
     */
    float ambientIntensity;

    /*
     * 空构造
     */
    AmbientLight();

    /*
     * 空析构
     */
    ~AmbientLight();

    /*
     * 构造
     */
    AmbientLight(float ambientIntensity);

    /*
     * 对象构造
     */
    AmbientLight(const AmbientLight &ambientLight);

    /*
     * 重载 =
     */
    AmbientLight &operator=(const AmbientLight &ambientLight);

    /*
     * 颜色取样
     */
    Color sample(const Ray &ray, const IntersectResult &itRet);
};

#endif //RAY_TRACER_LIGHT_H
