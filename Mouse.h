/*#ifndef MOUSE_H_
#define MOUSE_H_

#include "draw.h"

class Mouse{

    SDL_Rect arrRect0 = {SCREEN_WIDTH/2+70 , 300 , 225, 50};
    SDL_Rect arrRect1 = {SCREEN_WIDTH/2+110, 400 , 130, 50};
    Draw draw;
public:
    void mouseEvent(SDL_Renderer *renderer, SDL_Window *window);
    bool Check(const int &x, const int &y, const SDL_Rect &_rect);
};

#endif */// MOUSE_H_

