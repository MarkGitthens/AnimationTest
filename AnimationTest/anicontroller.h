#pragma once

//TODO: Create an animation class that holds data for each particular frame as well as the texture and update controller class accordingly.
//Sprite:
//      Animation Driven Rendering. (Will always use some type of anyimation to draw the sprite)
//          2d animation :
//      Animation sheet :
//      Image containing each from of the animation.
//          Animation Control File :
//      How long each frame should last on screen.
//          The height / width of each frame.
//          total number of frames.
//          order that each frame is presented.
//
//          Animation Controller :
//      Contains a map of all the Sprites available animations.
//          Controls what frame of the animation should be displayed.
//          Grants ability to change / play / stop / loop animation.
//
//          Rect GetFrame() : Return the rectangle


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"
#include <iostream>
#include <map>
#include "animation.h"

class AnimationController {
public:
    SDL_Rect getFrame();
    Texture getTexture();

    ; void addAnimation(std::string, Texture, int, int, int, int);
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