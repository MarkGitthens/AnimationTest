#pragma once
#include <SDL2\SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>
class Texture {
public:
    Texture() {};
    ~Texture() {};
    Texture(std::string path, SDL_Renderer* renderer) {
        loadFromPath(path, renderer);
    }
    bool loadFromPath(std::string, SDL_Renderer*);
    SDL_Texture* getTexture() { return gTexture; }

private:
    SDL_Texture* gTexture;
};