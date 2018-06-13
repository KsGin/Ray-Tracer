/*
 * File   : material
 * Author : KsGin 
 * Date   : 2018/6/13
 */

#include "../headers/material.h"

float Material::getReflectiveness(GEOMETRY geometry) {
    switch (geometry) {

        case NOGEO:
            return 0;
        case SPHERE:
            return 0.2;
        case PLANE:
            return 0.5;
    }
    return 0;
}

Color Material::getColor(GEOMETRY geometry, const Math::Vector3 &position) {
    switch (geometry) {

        case NOGEO:
            return Color::black();
        case SPHERE:
            return Color::blue() * 0.8;
        case PLANE:
            return abs(static_cast<int>(
                       floor(position._x * 0.5) +
                       floor(position._z * 0.5)) % 2) < 1 ?
                   Color::white() : Color::black();;
    }
    return Color::black();
}

float Material::getRefractiveness(GEOMETRY geometry) {
    switch (geometry) {

        case NOGEO:
            return 0;
        case SPHERE:
            return 1;
        case PLANE:
            return 1;
    }
}
