/*
 * File   : device
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#ifndef RAY_TRACER_DEVICE_H
#define RAY_TRACER_DEVICE_H

#include <SDL2/SDL.h>

/*
 * 设备类
 */
class Device {
    /*
     * window 指针
     */
    SDL_Window *window;
    /*
     * surface 指针
     */
    SDL_Surface *surface;
    /*
     * texture 指针
     */
    SDL_Texture *texture;
    /*
     * renderer 指针
     */
    SDL_Renderer *renderer;

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
};


#endif //RAY_TRACER_DEVICE_H
