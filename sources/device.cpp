/*
 * File   : device
 * Author : KsGin 
 * Date   : 2018/6/1
 */

#include "../headers/device.h"

Device::Device() {

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

    this->surface = SDL_LoadBMP("../resources/surface.bmp");
    if (!surface) {
        return -1;
    }

    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
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
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Device::updateRender() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) isQuit = true;
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

bool Device::windowShouldClose() {
    return isQuit;
}


