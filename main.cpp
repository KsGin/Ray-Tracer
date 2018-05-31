#include <iostream>
#include <SDL2/SDL.h>

const int width = 800;
const int height = 600;

int main() {

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                                          SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cout << "ERROR::" << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cout << "ERROR::" << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Surface *bmp = SDL_LoadBMP("../resources/surface.bmp");
    if (!bmp) {
        std::cout << "ERROR::" << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, bmp);
    if (!tex) {
        std::cout << "ERROR::" << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_FreeSurface(bmp);
    SDL_ShowWindow(window);

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tex, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}