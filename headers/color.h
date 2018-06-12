/*
 * File   : color
 * Author : KsGin 
 * Date   : 2018/6/3
 */

#ifndef RAY_TRACER_COLOR_H
#define RAY_TRACER_COLOR_H


#include <SDL2/SDL_system.h>

/*
 * 颜色类
 */
class Color {
public:
    /*
     * 数据定义
     */
    union {
        struct {
            float r, g, b, a;
        };
        struct {
            float x, y, z, w;
        };
    };

    /*
     * 空构造方法
     */
    Color();

    /*
     * 值构造方法
     */
    Color(float r, float g, float b, float a);

    /*
     * 引用拷贝
     */
    Color(const Color &color);

    /*
     * 重载 =
     */
    Color &operator=(const Color &color);

    /*
     * 重载 +
     */
    Color operator+(const Color &color);

    /*
     * 重载 -
     */
    Color operator-(const Color &color);

    /*
     * 重载 *
     */
    Color operator*(const Color &color);

    /*
     * 重载 /
     */
    Color operator/(const Color &color);

    /*
     * 重载 +
     */
    Color operator+(const float c);

    /*
     * 重载 -
     */
    Color operator-(const float c);

    /*
     * 重载 *
     */
    Color operator*(const float c);

    /*
     * 重载 /
     */
    Color operator/(const float c);

    /*
     * 限制颜色在 0 - 1 之间
     */
    Color &modulate();

    /*
     * 红色
     */
    static Color red();

    /*
     * 绿色
     */
    static Color green();

    /*
     * 蓝色
     */
    static Color blue();

    /*
     * 白色
     */
    static Color white();

    /*
     * 黑色
     */
    static Color black();
};


#endif //RAY_TRACER_COLOR_H
