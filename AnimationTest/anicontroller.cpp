#include "anicontroller.h"

SDL_Rect AnimationController::getFrame() {
    SDL_Rect frame;
    if (currentState) {
        currentTime = SDL_GetTicks();

        if (currentTime - startTime >= delayTime) {
            if (currentFrame == numFrames-1) {
                currentFrame = 0;
            } else {
                currentFrame++;
            }
            startTime = currentTime;
        }
    }
    return animations.at(currentAnimation).getFrame(currentFrame);
}

SDL_Texture* AnimationController::getTexture() {
    return currentTexture;
}

void AnimationController::addAnimation(std::string aniFile, SDL_Renderer* renderer) {
    Animation temp;
    temp.parseFile(aniFile, renderer);
    animations.emplace(temp.getName(), temp);
}

void AnimationController::setDefault(std::string aniTitle) {
    defaultAnimation = aniTitle;
}
void AnimationController::removeAnimation(std::string name) {
    if (animations.count(name)) {
        animations.erase(name);
        playAnimation(defaultAnimation);
    }
}

void AnimationController::playAnimation(std::string name) {
    if (currentAnimation != name && animations.count(name)) {
        currentAnimation = name;
        delayTime = animations.at(currentAnimation).getFrameDelay();
        currentTexture = animations.at(currentAnimation).getTexture().getTexture();
        numFrames = animations.at(currentAnimation).getFrameCount();
        startTime = SDL_GetTicks();
    }
}

void AnimationController::resumeAnimation() {
    currentState = AnimationStates::running;
    startTime = SDL_GetTicks();
}

void AnimationController::pauseAnimation() {
    currentState = AnimationStates::paused;
}