#include "draw.h"


void Draw::loadBackground(SDL_Renderer *renderer) {
	texture = loadTexture("picture\\bg.bmp", renderer);
	renderTexture(texture, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    image = loadTexture("picture\\game.bmp", renderer);
	renderTexture(image, renderer, 50, 30, 300 ,150 );

	SDL_Texture *score = loadTexture("picture\\score.bmp", renderer);
	renderTexture(score, renderer, 450, 50, 120, 70);

    SDL_Texture *highScore= loadTexture("picture\\highscore.bmp", renderer);
    renderTexture(highScore, renderer, 450, 130, 200, 70);


    SDL_Texture *exit= loadTexture("picture\\exit1.png", renderer);
    renderTexture(exit, renderer, SCREEN_WIDTH/2+110, 420, 130, 70);

    SDL_Texture *newGame = NULL;
    newGame= loadTexture("picture\\newGame1.png", renderer);
    renderTexture(newGame, renderer, SCREEN_WIDTH/2+70 , 300 , 225, 70);

    SDL_DestroyTexture(newGame);
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(image);
    SDL_DestroyTexture(score);
    SDL_DestroyTexture(highScore);
    SDL_DestroyTexture(exit);

}

void Draw::loadStart(SDL_Renderer *renderer)
{
    SDL_Texture *start = NULL;
    start= loadTexture("picture\\start.bmp", renderer);
    renderTexture(start, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture *play = NULL;
    play= loadTexture("picture\\play1.png", renderer);
    renderTexture(play, renderer, SCREEN_WIDTH/2-135, SCREEN_HEIGHT/2-20, 250, 125);

    SDL_Texture *exit = NULL;
    exit= loadTexture("picture\\exit1.png", renderer);
    renderTexture(exit, renderer, SCREEN_WIDTH/2-95, SCREEN_HEIGHT/2+140, 150, 100);

    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(start);
    SDL_DestroyTexture(play);
    SDL_DestroyTexture(exit);

}

void Draw::loadExit(SDL_Renderer *renderer, bool check)
{
    SDL_Texture *exit = NULL;
    exit= loadTexture("picture\\exit2.png", renderer);
    if (check)
       {
            renderTexture(exit, renderer,SCREEN_WIDTH/2+110, 420, 130, 70);
       }
    else
       {
            renderTexture(exit, renderer,SCREEN_WIDTH/2-95, SCREEN_HEIGHT/2+140, 150, 100);
       }
    SDL_DestroyTexture(exit);
    SDL_RenderPresent(renderer);
}

void Draw::loadNew(SDL_Renderer *renderer)
{
    SDL_Texture *newGame = NULL;
    newGame= loadTexture("picture\\newGame2.png", renderer);
    renderTexture(newGame, renderer, SCREEN_WIDTH/2+70 , 300 , 225, 70);
    SDL_RenderPresent(renderer);
}

void Draw::loadPlay(SDL_Renderer *renderer)
{
    SDL_Texture *play = NULL;
    play= loadTexture("picture\\play2.png", renderer);
    renderTexture(play, renderer, SCREEN_WIDTH/2-135, SCREEN_HEIGHT/2-20, 250, 125);
    SDL_DestroyTexture(play);
    SDL_RenderPresent(renderer);
}

void Draw::loadNumber(int const &_x, int const &_y, SDL_Renderer *renderer,Block block) {
	int number = block.get_value();
	SDL_Texture *tex = NULL;
	this->block.x = _x;
	this->block.y = _y;
	this->block.w = 80;
	this->block.h = 80;
	switch (number)
	{
	  case 0:
        {
		    SDL_SetRenderDrawColor(renderer, 194, 194, 163, 255);
		    SDL_RenderFillRect(renderer, &(this->block));
		    break;
	    }
	  case 2:
        {
            tex = loadTexture("picture\\2.bmp", renderer);
		    renderTexture(tex, renderer, _x, _y, 80, 80);
		    break;
        }
	  case 4:
        {
            tex = loadTexture("picture\\4.bmp", renderer);
		    renderTexture(tex, renderer, _x, _y, 80, 80);
		    break;
	    }
      case 8:
        {
            tex = loadTexture("picture\\8.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
	    }
	  case 16:
        {
            tex = loadTexture("picture\\16.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
        }
      case 32:
        {
            tex = loadTexture("picture\\32.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
        }
	  case 64:
        {
            tex = loadTexture("picture\\64.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
        }
	  case 128:
        {
            tex = loadTexture("picture\\128.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
        }
	  case 256:
        {
            tex = loadTexture("picture\\256.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
        }
	  case 512:
        {
            tex = loadTexture("picture\\512.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
        }
	  case 1024:
        {
            tex = loadTexture("picture\\1024.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
        }
	  case 2048:
        {
            tex = loadTexture("picture\\2048.bmp", renderer);
            renderTexture(tex, renderer, _x, _y, 80, 80);
            break;
        }
    }
	SDL_DestroyTexture(tex);
}

void Draw::LoadText(SDL_Renderer *renderer, const int &xp, const int &yp, const int &w, const int &h,const string &path) {
	font = TTF_OpenFont("font\\Turtles.ttf",600);
	SDL_Surface *surf = TTF_RenderText_Solid(font, path.c_str(), SDL_Color{ 255, 165,0 ,255});
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
	renderTexture(tex, renderer, xp, yp, w, h);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}

void Draw::gameOver_WinGame(const bool &win, SDL_Renderer *renderer)
{
    SDL_Texture* image = NULL;
    if(win)
    {
        image = loadTexture("picture//WinGame.bmp",renderer);
    }
    else
    {
        image = loadTexture("picture//GameOver.bmp",renderer);
    }
    renderTexture(image, renderer, 50, 300, 300, 150);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(image);
}




