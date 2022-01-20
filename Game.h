#ifndef GAME_H_
#define GAME_H_

#include "draw.h"
#include <SDL_ttf.h>
//#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
const SDL_Rect arrRect0 = {SCREEN_WIDTH/2+70 , 300 , 225, 70};
const SDL_Rect arrRect1 = {SCREEN_WIDTH/2+110, 420 , 130, 70};
const SDL_Rect arrRect2 = {SCREEN_WIDTH/2-135, SCREEN_HEIGHT/2-20, 250, 125};
const SDL_Rect arrRect3 = {SCREEN_WIDTH/2-95, SCREEN_HEIGHT/2+140, 150, 100};


class Game{
    Draw draw;
    int score;
    int highScore;
    Block **tab;
    const int xp = 25;
	const int yp = SCREEN_HEIGHT / 3;

public:
    Game();
    ~Game();
    void startGame(SDL_Renderer *renderer, SDL_Window *window);
    void showGame(SDL_Renderer *renderer);

    void showScore(SDL_Renderer *renderer,int score);
    void showHigh(SDL_Renderer *renderer,int highScore);
    int mouseEvent(SDL_Renderer *renderer);

    Block** createtab();


    bool checkWin(Block **&tab);
    bool checkPut(Block **&tab);
    bool checkLose(Block **&tab);


    bool rushUp(Block **&tab);
    int moveUp(Block **&tab);
    bool rushDown(Block **&tab);
    int moveDown(Block **&tab);
    bool rushRight(Block **&tab);
    int moveRight(Block **&tab);
    bool rushLeft(Block **&tab);
    int moveLeft(Block **&tab);

    void themSo(Block **&tab);
    void getHighScore();
    void saveHighScore();
    void restart();

    bool Check(const int &x, const int &y, const SDL_Rect &_rect);
};
#endif
