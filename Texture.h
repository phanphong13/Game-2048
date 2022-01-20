#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <ostream>
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const std::string WINDOW_TITLE = "Wellcome To 2048";



void logSDLError(std::ostream &os,const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);



SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

#endif
