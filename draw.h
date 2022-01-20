#ifndef DRAW_BLOCK_H
#define DRAW_BLOCK_H


#include "block.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "Texture.h"


class Draw {
	SDL_Rect block;
	SDL_Texture *texture = NULL;
	SDL_Texture *image = NULL;
	TTF_Font *font = NULL;

public:
	void loadBackground (SDL_Renderer *renderer);
	void loadStart(SDL_Renderer *renderer);
	void loadNew(SDL_Renderer *renderer);

	void loadPlay(SDL_Renderer *renderer);
	void loadExit(SDL_Renderer *renderer, bool check);
	void loadNumber (int const &_x, int const &_y, SDL_Renderer *renderer,Block block);
	void LoadText(SDL_Renderer *renderer, const int &xp, const int &yp, const int &w, const int &h, const string &path);
	void gameOver_WinGame(const bool &win, SDL_Renderer *renderer);

};

#endif
