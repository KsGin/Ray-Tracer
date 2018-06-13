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
#include "plane.h"
#include "light.h"

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
    std::vector<Sphere *> spheres;

    /*
     * 平面
     */
    std::vector<Plane *> planes;

    /*
     * 相机
     */
    Camera *camera;

    /*
     * 光线
     */
    DirectionLight *directionLight;

    /*
     * 构造方法
     */
    Scene();

    /*
     * 构造方法
     */
    Scene(const std::vector<Sphere *> &models, std::vector<Plane *> planes,
          Camera *camera, DirectionLight *directionLight,
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
