#include "game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    
    gWindow = SDL_CreateWindow("Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win_width, win_height, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
    IMG_Init(IMG_INIT_PNG);
    playerAnimations.addAnimation("animations/idle.xml", gRenderer);
    playerAnimations.addAnimation("animations/hadouken.xml", gRenderer);
    playerAnimations.playAnimation("Idle");
    update();

    

    //TODO: Do error checking to ensure proper initialization of SDL and it's components
}

void Game::update() {
    //Set constant think rate to ensure consistent performance.
    while (running) {
        handleInput();
        think();
        render();
    }
    destroy();
}
void Game::handleInput() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_p:
                playerAnimations.pauseAnimation();
                break;
            case SDLK_r:
                playerAnimations.resumeAnimation();
                break;
            }
        }
    }
    //TODO: Get input from player
}

void Game::think() {
    //TODO: Update game state
}

void Game::updateAnimations() {
    
}
void Game::render() {
    SDL_RenderClear(gRenderer);
    SDL_Rect renderTo;
    renderTo.x = win_width / 2 - playerAnimations.getFrame().w /2;
    renderTo.y = win_height / 2 - playerAnimations.getFrame().h;
    renderTo.w = playerAnimations.getFrame().w;
    renderTo.h = playerAnimations.getFrame().h;
    SDL_RenderCopy(gRenderer, playerAnimations.getTexture().getTexture(), &playerAnimations.getFrame(), &renderTo);
    SDL_RenderPresent(gRenderer);
}

void Game::destroy() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    //TODO: free memory and quit SDL + dependencies
}

