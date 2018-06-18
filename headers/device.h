/*
 * File   : device
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#ifndef RAY_TRACER_DEVICE_H
#define RAY_TRACER_DEVICE_H

#include <SDL2/SDL.h>
#include "color.h"

/*
 * 设备类
 */
class Device {
    /*
     * window 指针
     */
    SDL_Window *window;
    /*
     * texture 指针
     */
    SDL_Texture *texture;
    /*
     * renderer 指针
     */
    SDL_Renderer *renderer;

    /*
     * pixels 指针
     */
    Uint8 *pixels;

    /*
     * 窗口属性 宽 高
     */
    int width, height;

    /*
     * 是否全屏
     */
    bool isScreenFull;

    /*
     * 是否退出
     */
    bool isQuit;

    /*
     * SDL 事件
     */
    SDL_Event event;

public:

    /*
     * 空构造方法
     */
    Device();

    /*
     * 析构方法
     */
    ~Device();

    /*
     * 初始化设备
     */
    bool initialize(int width, int height, bool isScreenFull);

    /*
     * 显示窗口
     */
    void show();

    /*
     * 销毁窗口
     */
    void destory();

    /*
     * 更新渲染
     */
    void updateRender();

    /*
     * 是否退出
     */
    bool windowShouldClose();

    /*
     * 修改像素颜色
     */
    void setPixelColor(const int x, const int y, const Color &color);

    /*
     * 获得像素颜色
     */
    Color getPixelColor(const int x, const int y);

    /*
     * 更新像素数据
     */
    void updatePixelsColor();

    /*
     * 更新窗口标题
     */
    void updateWindowTitle(const char *title);

    /*
     * 获得当前系统时间（毫秒）
     */
    long getCurrentTime();

    /*
     * 事件处理
     */
    void handleEvent();

    /*
     * 数值限制
     */
    static float clamp(const float &value, const float &maxValue = 1, const float &minValue = 0);
};


#endif //RAY_TRACER_DEVICE_H
