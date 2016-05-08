#pragma once

#include <SDL.h>
#include "texture.h"    
#include <SDL_image.h>
#include <string>
#include "anicontroller.h"
class Game {
public:
    Game();
    ~Game();
    void init();
    void destroy();

    void handleInput();
    void think();
    void render();
    
    void updateAnimations();
    void update();

private:
    SDL_Texture* loadTexture(std::string path);
    AnimationController playerAnimations; 
protected:
    int win_width  = 620;
    int win_height = 480;
    bool running = true;
    
    SDL_Renderer* gRenderer = nullptr;
    SDL_Window* gWindow = nullptr;
};