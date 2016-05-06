#include "anicontroller.h"
/*
    Assuming 5 frames per row in the animation texture
*/
SDL_Rect AnimationController::getFrame() {
    SDL_Rect frame;
    if (currentState) {
        currentTime = SDL_GetTicks();

        if (currentTime - startTime >= delayTime) {
            if (currentFrame == numFrames-1) {
                currentFrame = 0;
            }
            else {
                currentFrame++;
            }
            startTime = currentTime;
        }
    }

    //frame.w = frameWidth;
    //frame.h = frameHeight;
    //frame.x = (currentFrame % 22) * frame.w;
    //frame.y = 0;
    delayTime = 66;
    std::cout << animations.at(currentAnimation)->getFrame(currentFrame).x << " " << animations.at(currentAnimation)->getFrame(currentFrame).y << std::endl;
    return animations.at(currentAnimation)->getFrame(currentFrame);
}

Texture AnimationController::getTexture() {
    return animations.at(currentAnimation)->getTexture();
}

//void AnimationController::addAnimation(std::string path, Texture animSheet, int frameCount, int w, int h, int frameDelay) {
//    animations.emplace(path, animSheet);
//    numFrames = frameCount;
//    frameWidth = w;
//    frameHeight = h;
//    delayTime = frameDelay;
//}

void AnimationController::addAnimation(std::string aniFile, SDL_Renderer* renderer) {
    Animation* tempAnimation = new Animation();
    tempAnimation->parseFile(aniFile, renderer);
    std::cout << tempAnimation->getName() << std::endl;
    std::cout << tempAnimation->getFrame(0).x << std::endl;
    animations.emplace(tempAnimation->getName(), tempAnimation);
    
}

void AnimationController::removeAnimation(std::string name) {
    //TODO: Fix memory leak;
        animations.erase(name);
}

void AnimationController::playAnimation(std::string name) {
    currentAnimation = name;
    numFrames = animations.at(currentAnimation)->getFrameCount();
    startTime = SDL_GetTicks();
}

void AnimationController::resumeAnimation() {
    currentState = AnimationStates::running;
    startTime = SDL_GetTicks();
}

void AnimationController::pauseAnimation() {
    currentState = AnimationStates::paused;
}