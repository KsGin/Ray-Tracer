/*
 * File   : material
 * Author : KsGin 
 * Date   : 2018/6/13
 */

#ifndef RAY_TRACER_MODEL_H
#define RAY_TRACER_MODEL_H

#include "color.h"
#include "../include/math/vector.hpp"

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
 * 模型类
 */
class Material {
public:
    /*
     * 反射度
     */
    static float getReflectiveness(GEOMETRY geometry);

    /*
     * 颜色
     */
    static Color getColor(GEOMETRY geometry , const Math::Vector3& position);
};


#endif //RAY_TRACER_MODEL_H
