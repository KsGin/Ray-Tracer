#### Ray Tracer

项目具体描述：使用 C++ 实现的简易光线追踪器（ 使用 SDL 图形框架 ）

项目时间：2018.6.1 —— ...

部分截图：

1. 单光源（定向光）反射

    ![just reflect1](https://image.ibb.co/hmGj5J/WX20180614_114036_2x.png)

2. 多光源（点光源）反射

    ![just reflect2](https://image.ibb.co/mMDgLJ/WX20180615_135744_2x.png)
    
3. 多光源（点光源）反射，阴影
    
    ![reflect and shadow](https://image.ibb.co/ejuiNy/WX20180618_131716_2x.png)

内容实现：

1. 基本渲染
2. 带最大次数限制的递归光线追踪，反射
3. 基础 phong 模型，定向光，点光源（多光源）
4. 阴影

留坑待填：

1. 折射
2. 抗锯齿

文件结构（仅代码）：

1. `headers/`：头文件夹
    + `camera.h`：`Camera` , `PerspectiveCamera` , `OrthoCamera` 类头文件（核心类，生成光线），封装摄像机相关
    + `color.h`：`Color` 类头文件，封装颜色数据及基本操作
    + `device.h`：`Device` 类头文件（核心类），封装设备接口
    + `model.h`：`Model` , `Shpere` , `Plane` 等数据头文件（核心文件），计算光线与模型相交
    + `ray.h`：`Ray` 类头文件，定义光线数据及基本操作
    + `scene.h`：`Scene` 类头文件（核心类），封装场景数据与基本操作（渲染）
    + `light.h`: `PointLight` , `DirectionLight` 类封装即基本操作
2. `include/`：库文件夹
    + `math/`：[自用数学库](https://github.com/KsGin/Math-Lib)
        + `vector.hpp`：向量库，封装 `Vector2` ，`Vector2`
        + `matrix.hpp`：矩阵库，封装 `Matrix`
3. `sources/`：源文件夹
    + `camera.cpp`：`Camera` , `PerspectiveCamera` , `OrthoCamera` 类源文件（核心类，生成光线），封装摄像机相关
    + `color.cpp`：`Color` 类源文件，封装颜色数据及基本操作
    + `device.cpp`：`Device` 类源文件（核心类），封装设备接口
    + `model.cpp`：`Model` , `Shpere` , `Plane` 等数据源文件（核心文件），计算光线与模型相交
    + `ray.cpp`：`Ray` 类源文件，定义光线数据及基本操作
    + `scene.cpp`：`Scene` 类源文件（核心类），封装场景数据与基本操作（渲染）
    + `light.cpp`: `PointLight` , `DirectionLight` 类封装即基本操作

4. `main.cpp` ：main 文件（入口）



