#include "texture.h"

bool Texture::loadFromPath(std::string path, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = nullptr;
 
    tempSurface = IMG_Load(path.c_str());
    if (tempSurface) {
        
        gTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        if (!gTexture) {
            std::cout << "Couldn't create texture from surface." << std::endl;
        }
        SDL_FreeSurface(tempSurface);
    }
    else {
        std::cout << "Couldn't create surface." << std::endl;
    }
    return gTexture;
}