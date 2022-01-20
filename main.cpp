#include <iostream>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Game.h"
using namespace std;


int main(int arc, char*argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    Game game;
    Draw draw;
    bool continueRun = true;
    SDL_Event e;
    draw.loadStart(renderer);
    while (continueRun)
    {
        draw.loadStart(renderer);
        while(SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
                {
                case SDL_QUIT:
                    {
                        continueRun = false;
                        break;
                    }
                case SDL_MOUSEMOTION:
                    {
                        int xp = e.motion.x;
                        int yp = e.motion.y;
                        if (game.Check(xp,yp,arrRect2))
                        {
                            draw.loadPlay(renderer);
                            SDL_RenderPresent(renderer);
                        }
                        if (game.Check(xp,yp,arrRect3))
                        {

                            draw.loadExit(renderer,false);
                            SDL_RenderPresent(renderer);
                        }

                        break;
                    }
                case SDL_MOUSEBUTTONDOWN:
                    {
                        int x = e.motion.x;
                        int y = e.motion.y;
                        if (game.Check(x,y,arrRect3))
                        {
                            continueRun = false;
                        }
                        if (game.Check(x,y,arrRect2))
                        {
                            game.startGame(renderer,window);
                            continueRun = false;
                        }
                        break;
                    }

                }
        }
        SDL_RenderPresent(renderer);
    }


    quitSDL(window, renderer);
    return 0;
}

