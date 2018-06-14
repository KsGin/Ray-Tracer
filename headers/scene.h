/*
 * File   : scene
 * Author : KsGin 
 * Date   : 2018/6/7
 */

#ifndef RAY_TRACER_SCENE_H
#define RAY_TRACER_SCENE_H

#include <vector>
#include "camera.h"
#include "device.h"
#include "light.h"
#include "model.h"

/*
 * 场景类
 */
class Scene {

    /*
     * 最大反射次数
     */
    float maxReflect;

public:
    /*
     * 屏幕大小
     */
    int screenWidth, screenHeight;

    /*
     * 模型数组
     */
    std::vector<Model *> models;

    /*
     * 相机
     */
    Camera *camera;

    /*
     * 光源
     */
    std::vector<Light *> lights;

    /*
     * 构造方法
     */
    Scene();

    /*
     * 构造方法
     */
    Scene(const std::vector<Model *> &models,
          const std::vector<Light *> &lights,
          Camera *camera,
          const int &screenWidth,
          const int &screenHeight);

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
    void renderScene(Device *device, int maxReflect);

    /*
     * 递归追踪
     */
    Color rayTrace(const Ray &ray, float maxReflect);
};


#endif //RAY_TRACER_SCENE_H
