#ifndef GAME_HPP
#define GAME_HPP

#include<iostream>
#include"SDL.h"
#include"SDL_image.h"
#include<string>
#include"Player.h"
#include "Board.h"


using namespace std;
class Button;
class Mouse;
class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

private:

    Player* player1;
    Player* player2;
    Board* board;
    Button* roll_dice;
    Mouse* mouse;
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;


};

#endif
