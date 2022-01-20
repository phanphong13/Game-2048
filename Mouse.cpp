/*#include "Mouse.h"

void Mouse::mouseEvent(SDL_Renderer *renderer, SDL_Window *window){
    SDL_Event e;
	while(true) {
        SDL_RenderPresent(renderer);
		while (SDL_PollEvent(&e)) {
		    switch(e.type) {
            case SDL_QUIT:
                {
                    quitSDL(window, renderer);
                    //return false;
                }
			case SDL_MOUSEMOTION:
			    {
                    int x = e.motion.x;
                    int y = e.motion.y;
                    if (Check(x,y,arrRect0)) draw.loadNew(renderer);
			    }
		    }
		}
	}

};


bool Mouse::Check(const int &x, const int &y, const SDL_Rect &_rect)
{
    if (x >= _rect.x && x <= _rect.x + _rect.w && y >= _rect.y &&y <= _rect.y + _rect.h) {
		return true;
	}
	return false;
} */
