/*
 * File   : scene
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#ifndef RAY_TRACER_SCENE_H
#define RAY_TRACER_SCENE_H

#include <vector>
#include "sphere.h"
#include "camera.h"
#include "device.h"

/*
 * 场景类
 */
class Scene {
public:
    /*
     * 屏幕大小
     */
    int screenWidth, screenHeight;

    /*
     * 模型数组
     */
    std::vector<Sphere> spheres;

    /*
     * 相机
     */
    Camera *camera;

    /*
     * 构造方法
     */
    Scene();

    /*
     * 构造方法
     */
    Scene(const std::vector<Sphere> &models, Camera *camera, const int &screenWidth, const int &screenHeight);

    /*
     * 析构方法
     */
    ~Scene();

    /*
     * 引用拷贝
     */
    Scene &operator=(const Scene &scene);

    /*
     * 渲染
     */
    void RenderScene(Device *device);
};


#endif //RAY_TRACER_SCENE_H
