#include "Game.h"

Game::Game()
{
    score=0;
}

Game::~Game(){}

void Game::startGame(SDL_Renderer *renderer, SDL_Window *window)
{
    bool checkRun=true;
    tab = createtab();

    getHighScore();
    bool check;
    while (checkRun)
    {
         SDL_Event e;
         showGame(renderer);
         showScore(renderer,score);
         showHigh(renderer,highScore);
         while(SDL_PollEvent(&e) != 0)
            {
                switch (e.type)
                {
                case SDL_QUIT:
                    {
                        checkRun = false;
                        break;
                    }
                case SDL_KEYDOWN:
                    {
                        check = false;
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_UP:
                            {
                                if (rushUp(tab))
                                {
                                    score += moveUp(tab);
                                    check = true;
                                    themSo(tab);
                                }
                                break;
                            }
                        case SDLK_DOWN:
                            {
                                if (rushDown(tab))
                                {
                                    score += moveDown(tab);
                                    check = true;
                                    themSo(tab);
                                }
                                break;
                            }
                        case SDLK_RIGHT:
                            {
                                if (rushRight(tab))
                                {
                                    score += moveRight(tab);
                                    check = true;
                                    themSo(tab);
                                }
                                break;
                            }
                        case SDLK_LEFT:
                            {
                                if (rushLeft(tab))
                                {
                                    score += moveLeft(tab);
                                    check = true;
                                    themSo(tab);
                                }
                                break;
                            }

                        }
                        if (check)
                        {
                            if (score > highScore) highScore = score;
                            showGame(renderer);
                            showScore(renderer,score);
                            showHigh(renderer,highScore);
                            if (checkWin(tab))
                            {
                                draw.gameOver_WinGame(true,renderer);
                                if(mouseEvent(renderer) == 0)
                                        restart();
                                    else
                                        return;
                            }
                            if (checkLose(tab))
                            {
                                draw.gameOver_WinGame(false,renderer);
                                if(mouseEvent(renderer) == 0)
                                        restart();
                                    else
                                        return;
                            }
                        }

                    }
                case SDL_MOUSEMOTION:
                    {
                        int x = e.motion.x;
                        int y = e.motion.y;
                        if (Check(x,y,arrRect0))
                        {
                            draw.loadNew(renderer);
                        }

                        if (Check(x,y,arrRect1))
                        {
                            draw.loadExit(renderer,true);
                        }
                       break;

                    }
                case SDL_MOUSEBUTTONDOWN:
                    {
                       int x = e.motion.x;
                       int y = e.motion.y;
                       if (Check(x,y,arrRect0))
                        {

                           restart();
                        }
                        if (Check(x,y,arrRect1))
                        {
                            checkRun = false;
                        }
                       break;
                    }

                }

            }


        SDL_RenderPresent(renderer);
    }
     saveHighScore();

}

int Game::mouseEvent(SDL_Renderer *renderer)
{
    SDL_Event e;
    while(true)
    {

        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
            case SDL_QUIT:
                return 1;

            case SDL_MOUSEMOTION:
                {
                    int x = e.motion.x;
                    int y = e.motion.y;
                    if (Check(x,y,arrRect0))
                        {
                            draw.loadNew(renderer);
                            SDL_RenderPresent(renderer);
                        }

                        if (Check(x,y,arrRect1))
                        {
                            draw.loadExit(renderer,true);
                            SDL_RenderPresent(renderer);
                        }
                       break;

                }
            case SDL_MOUSEBUTTONDOWN:
                {
                    int x = e.motion.x;
                    int y = e.motion.y;
                    if (Check(x,y,arrRect0))
                         return 0;
                    if (Check(x,y,arrRect1))
                         return 1;

                }
            }
        }
    }
}
void Game::restart()
{
    tab=createtab();
    score = 0;
}

void Game::showGame(SDL_Renderer *renderer)
{
    draw.loadBackground(renderer);
    for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			draw.loadNumber(xp + 90 * j, yp + 90 * i, renderer,tab[i][j]);
		}
	}

}

void Game::showScore(SDL_Renderer *renderer,int score)
{
    string diem;
	ostringstream convert;
	convert << score;
	diem = convert.str();
	draw.LoadText(renderer,580,58,50,70,diem);
}

void Game::showHigh(SDL_Renderer *renderer,int highScore)
{
    string diem;
	ostringstream convert;
	convert << highScore;
	diem = convert.str();
	draw.LoadText(renderer,655,125,70,70,diem);
}
Block** Game::createtab(){
    Block **tab;
	tab = new Block *[4];
	for (int i = 0; i < 4; ++i) tab[i] = new Block[4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tab[i][j] = 0;
		}
	}
    themSo(tab);
    themSo(tab);
	return tab;
}

bool Game::checkWin (Block **&tab){
    bool win = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (tab[i][j].get_value() == 2048) win = 1;
		}
	}

	return win;
}

bool Game::checkPut(Block **&tab)
{
    bool put = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (tab[i][j].get_value() == 0) put = 1;
		}
	}

	return put;
}

bool Game::checkLose(Block **&tab)
{
    bool lose = 1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j].get_value() == tab[i][j + 1].get_value()) lose = 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (tab[i][j].get_value() == tab[i + 1][j].get_value()) lose = 0;
		}
	}

	if (checkPut(tab)) lose = 0;

	return lose;
}


void Game::getHighScore()
{
	fstream file;
    file.open("file\\highScore.txt", ios::in);
    if(file.is_open())
    {
        if(file.eof())
        {
            file.close();
            return;
        }
        else
        {
            string line;
            while(getline(file, line))
            {
                highScore = stoi(line);
            }
        }
    }
    else
    {
        cout << "error open file highScore.txt" << endl;
    }
    file.close();
}
 void Game::saveHighScore()
 {
    ofstream file;
    file.open("file\\highScore.txt");
    if(file.is_open())
    {
        file << highScore;
    }
    else
        cout << "error open file highScore.txt" << endl;
    file.close();
 }

 bool Game::Check(const int &xx, const int &yy, const SDL_Rect &_rect)
{
    if (xx >= _rect.x && xx <= _rect.x + _rect.w && yy >= _rect.y &&yy <= _rect.y + _rect.h) {
		return true;
	}
	return false;
}


/**************************************************/

void Game::themSo(Block **&tab)
{
    if (checkPut(tab)) {
		int values[2] = { 2, 4};
		int value = values[rand() % 2];

		int X = rand() % 4;
		int Y = rand() % 4;
		if (tab[X][Y].get_value() == 0) tab[X][Y] = 2;
		else {
			while (tab[X][Y].get_value() != 0) {
				X = rand() % 4;
				Y = rand() % 4;
			}
			tab[X][Y] = value;
		}
	}
}

bool Game::rushRight(Block **&tab) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j].get_value() == tab[i][j + 1].get_value() && tab[i][j].get_value() != 0) {
				return true;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j > 0; j--) {
			if (tab[i][j].get_value() == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (tab[i][k].get_value() != 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
int Game :: moveRight(Block **&tab) {
	int point = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j > 0; j--) {
			if (tab[i][j].get_value() != 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (tab[i][j] == tab[i][k]) {
						tab[i][j] = tab[i][j] + tab[i][k];
						point += tab[i][j].get_value();
						break;
					}
					if (tab[i][j].get_value() != tab[i][k].get_value() && tab[i][k].get_value() != 0) {
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j > 0; j--) {
			if (tab[i][j].get_value() == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (tab[i][k].get_value() != 0) {
						tab[i][j] = tab[i][k];
						tab[i][k] = 0;
						break;
					}
				}
			}
		}
	}
	return point;
}
bool Game::rushLeft(Block **&tab) {
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j > 0; j--) {
			if (tab[i][j].get_value() == tab[i][j - 1].get_value() && tab[i][j].get_value() != 0) {
				return true;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j].get_value() == 0) {
				for (int k = j + 1; k < 4; k++) {
					if (tab[i][k].get_value() != 0) return true;
				}
			}
		}
	}
	return false;
}
int Game :: moveLeft(Block **&tab) {
	int point=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j].get_value() != 0) {
				for (int k = j + 1; k < 4; k++) {
					if (tab[i][j] == tab[i][k]) {
						tab[i][j] = tab[i][j] + tab[i][k];
						point += tab[i][j].get_value();
						break;
					}
					if (tab[i][j].get_value() != tab[i][k].get_value() && tab[i][k].get_value() != 0) {
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j].get_value() == 0) {
				for (int k = j + 1; k < 4; k++) {
					if (tab[i][k].get_value() != 0) {
						tab[i][j] = tab[i][k];
						tab[i][k] = 0;
						break;
					}
				}
			}
		}
	}
	return point;
}
bool Game::rushUp(Block **&tab) {
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 3; i++) {
			if (tab[i][j].get_value() == tab[i + 1][j].get_value() && tab[i][j].get_value() != 0) {
				return true;
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 3; i++) {
			if (tab[i][j].get_value() == 0) {
				for (int k = i + 1; k < 4; k++) {
					if (tab[k][j].get_value() != 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
int Game ::moveUp(Block **&tab) {
	int point = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 3; i++) {
			if (tab[i][j].get_value() != 0) {
				for (int k = i + 1; k < 4; k++) {
					if (tab[i][j].get_value() == tab[k][j].get_value()) {
						tab[i][j] = tab[i][j] + tab[k][j];
						point += tab[i][j].get_value();
						break;
					}
					if (tab[i][j].get_value() != tab[k][j].get_value() && tab[k][j].get_value() != 0) {
						break;
					}
				}
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 3; i++) {
			if (tab[i][j].get_value() == 0) {
				for (int k = i + 1; k < 4; k++) {
					if (tab[k][j].get_value() != 0) {
						tab[i][j] = tab[k][j];
						tab[k][j] = 0;
						break;
					}
				}
			}
		}
	}
	return point;
}
bool Game::rushDown(Block **&tab) {
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 3; i++) {
			if (tab[i][j].get_value() == tab[i + 1][j].get_value() && tab[i][j].get_value() != 0) {
				return true;
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		for (int i = 3; i > 0; i--) {
			if (tab[i][j].get_value() == 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (tab[k][j].get_value() != 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
int Game :: moveDown(Block **&tab) {
	int point = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 3; i > 0; i--) {
			if (tab[i][j].get_value() != 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (tab[i][j] == tab[k][j]) {
						tab[i][j] = tab[i][j] + tab[k][j];
						point += tab[i][j].get_value();
						break;
					}
					if (tab[i][j].get_value() != tab[k][j].get_value() && tab[k][j].get_value() != 0) break;
				}
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		for (int i = 3; i > 0; i--) {
			if (tab[i][j].get_value() == 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (tab[k][j].get_value() != 0) {
						tab[i][j] = tab[k][j];
						tab[k][j] = 0;
						break;
					}
				}
			}
		}
	}
	return point;
}

