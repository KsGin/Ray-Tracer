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
            Uint8 r, g, b, a;
        };
        struct {
            Uint8 x, y, z, w;
        };
    };

    /*
     * 空构造方法
     */
    Color();

    /*
     * 值构造方法
     */
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

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
    Color operator+(const Uint8 c);

    /*
     * 重载 -
     */
    Color operator-(const Uint8 c);

    /*
     * 重载 *
     */
    Color operator*(const Uint8 c);

    /*
     * 重载 /
     */
    Color operator/(const Uint8 c);
};


#endif //RAY_TRACER_COLOR_H
