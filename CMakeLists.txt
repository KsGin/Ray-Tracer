cmake_minimum_required(VERSION 3.10)
project(Ray_Tracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ray_Tracer
        main.cpp
        include/math/matrix.hpp
        include/math/vector.hpp
        sources/ray.cpp
        headers/ray.h
        sources/sphere.cpp
        headers/sphere.h
        sources/intersect.cpp
        headers/intersect.h sources/camera.cpp headers/camera.h sources/device.cpp headers/device.h sources/color.cpp headers/color.h sources/cube.cpp headers/cube.h sources/scene.cpp headers/scene.h)

target_link_libraries(Ray_Tracer /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)