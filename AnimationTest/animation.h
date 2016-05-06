#pragma once
#include <SDL2\SDL.h>
#include <string>
#include <tinyxml2.h>
#include "texture.h"

//Frame:
// functions:
//     SDL_Rect frameDimensions
//
//         Animation :
// Functions:
//     int getFrameCount();
//     string getName();
//     SDL_Rect getFrame();
//     bool parseFile(string path);
// Variables:
//     Frames[frameCount]
//         string title
//         int frameCount

class Animation {
public:
    Animation() {};
    ~Animation() {};
    int getFrameCount() { return frameCount; }
    std::string getName() { return title; }
    SDL_Rect getFrame(int frameNumber) { return frameList[frameNumber]; }
    Texture getTexture() { return spriteSheet; }

 /*   <animation>
        <name>Idle< / name>
        <image>idle.png< / image>
        <framecount>10< / framecount>
        <loopable>true< / loopable>
        <reversible>true< / reversible>
        <frames>
            <frame x = "16" y = "11" width = "79" height = "104" / >
            <frame x = "110" y = "11" width = "79" height = "104" / >
            <frame x = "210" y = "8" width = "79" height = "109" / >
            <frame x = "310" y = "6" width = "79" height = "111" / >
            <frame x = "407" y = "9" width = "79" height = "113" / >
            <frame x = "515" y = "9" width = "79" height = "112" / >
            <frame x = "617" y = "8" width = "79" height = "112" / >
            <frame x = "720" y = "8" width = "79" height = "111" / >
            <frame x = "827" y = "8" width = "79" height = "110" / >
            <frame x = "929" y = "12" width = "79" height = "106" / >
        < / frames>
      < / animation>*/
    bool parseFile(std::string path, SDL_Renderer* renderer) {
        tinyxml2::XMLDocument doc;
        doc.LoadFile(path.c_str());
        tinyxml2::XMLElement* animStart = doc.FirstChildElement("animation");
        title = animStart->FirstChildElement("name")->GetText();
        std::cout << title << std::endl;
        spriteSheet.loadFromPath(animStart->FirstChildElement("image")->GetText(), renderer);
        animStart->FirstChildElement("framecount")->QueryIntText(&frameCount);
        std::cout << frameCount << std::endl;

        tinyxml2::XMLElement* frameNode = animStart->FirstChildElement("frames");
        
        tinyxml2::XMLElement* frameElement = frameNode->FirstChildElement("frame");
        frameList = new SDL_Rect[frameCount];
        for (int i = 0; i < frameCount; i++) {
            frameList[i].x = frameElement->IntAttribute("x");
            frameList[i].y = frameElement->IntAttribute("y");
            frameList[i].w = frameElement->IntAttribute("width");
            frameList[i].h = frameElement->IntAttribute("height");

            std::cout << frameList[i].x << ", " << frameList[i].y << std::endl;
        
            frameElement = frameElement->NextSiblingElement("frame");
        }
        return true;
    }
private:
    Texture spriteSheet;
    SDL_Rect *frameList;
    std::string title;
    int frameCount;
};

