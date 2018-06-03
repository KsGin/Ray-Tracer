/*
 * File   : device
 * Author : KsGin
 * Date   : 2018/6/1
 */

#include "../headers/device.h"

Device::Device() {
    this->pixels = 0;
    this->window = 0;
    this->renderer = 0;
    this->texture = 0;
}

Device::~Device() {
    if (this->pixels) {
        delete[] this->pixels;
        this->pixels = 0;
    }
}

bool Device::initialize(int width, int height, bool isScreenFull) {

    this->width = width;
    this->height = height;
    this->isScreenFull = isScreenFull;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return false;
    }

    Uint32 windowAttr = SDL_WINDOW_RESIZABLE;
    if (this->isScreenFull) {
        windowAttr |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    this->window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    this->width, this->height, windowAttr);
    if (!window) {
        return false;
    }

    if (this->isScreenFull) {
        SDL_GetWindowSize(this->window, &this->width, &this->height);
    }

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        return false;
    }

    this->pixels = new Uint8[this->width * this->height * 4];
    memset(this->pixels, 0, static_cast<size_t>(this->width * this->height * 4));
    if (!this->pixels) {
        return false;
    }

    this->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, this->width,
                                      this->height);
    if (!texture) {
        return -1;
    }

    this->isQuit = false;
    return true;
}

void Device::show() {
    SDL_ShowWindow(window);
}

void Device::destory() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Device::updateRender() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) isQuit = true;
    }
    updatePixelsColor();
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

bool Device::windowShouldClose() {
    return isQuit;
}

void Device::setPixelColor(const int x, const int y, const Color &color) {

    int idx = (y * width + x) * 4;

    this->pixels[idx - 1] = color.a;
    this->pixels[idx - 2] = color.b;
    this->pixels[idx - 3] = color.g;
    this->pixels[idx - 4] = color.r;

}

void Device::updatePixelsColor() {
    SDL_UpdateTexture(this->texture, nullptr, this->pixels, width * 4);
}



