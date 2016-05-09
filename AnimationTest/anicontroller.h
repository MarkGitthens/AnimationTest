#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "texture.h"
#include <iostream>
#include <map>
#include "animation.h"

class AnimationController {
public:
    SDL_Rect getFrame();
    Texture getTexture();

    void addAnimation(std::string aniFile, SDL_Renderer* renderer);
    void removeAnimation(std::string);
    void playAnimation(std::string);
    void resumeAnimation();
    void pauseAnimation();
protected:
private:
    enum AnimationStates {
        paused,
        running
    };

    int currentFrame = 0;
    int startTime = 0;
    int currentTime = 0;
    int delayTime = 0;

    int numFrames = 0;
    int frameWidth, frameHeight;
    std::string currentAnimation = "Idle";
    
    int currentState = AnimationStates::running;
    std::map<std::string, Animation*> animations;
};