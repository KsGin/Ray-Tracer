/*
 * File   : color
 * Author : KsGin 
 * Date   : 2018/6/3
 */

#include "../headers/color.h"

Color::Color() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->x = r;
    this->y = g;
    this->z = b;
    this->w = a;
}

Color::Color(const Color &color) {
    this->r = color.r;
    this->g = color.g;
    this->b = color.b;
    this->a = color.a;
}

Color &Color::operator=(const Color &color) {
    this->r = color.r;
    this->g = color.g;
    this->b = color.b;
    this->a = color.a;
    return *this;
}

Color Color::operator+(const Color &color) {
    return Color(r + color.r, g + color.g, b + color.b, a + color.a);
}

Color Color::operator-(const Color &color) {
    return Color(r - color.r, g - color.g, b - color.b, a - color.a);
}

Color Color::operator*(const Color &color) {
    return Color(r * color.r, g * color.g, b * color.b, a * color.a);
}

Color Color::operator/(const Color &color) {
    return Color(r / color.r, g / color.g, b / color.b, a / color.a);
}

Color Color::operator+(const Uint8 c) {
    return Color(r + c, g + c, b + c, a + c);
}

Color Color::operator-(const Uint8 c) {
    return Color(r - c, g - c, b - c, a - c);
}

Color Color::operator*(const Uint8 c) {
    return Color(r * c, g * c, b * c, a * c);
}

Color Color::operator/(const Uint8 c) {
    return Color(r / c, g / c, b / c, a / c);
}
