#ifndef GAME_HPP
#define GAME_HPP

#include<iostream>
#include<string>
#include"Player.h"
#include "Board.h"
#include "Game.h"


using namespace std;
class Board;
class Game {
public:
    Game();
    ~Game();

    bool running() { return isRunning; }

private:

    Player* player1;
    Player* player2;
    Board* board;
    bool isRunning;


};

#endif
