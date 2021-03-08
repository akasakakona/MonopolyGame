#ifndef GAME_HPP
#define GAME_HPP

#include<iostream>
#include<string>
#include <vector>
#include"Player.h"
#include "Property.h"
#include "Game.h"
// #include "ChanceCard.h"
// #include "CommunityCard.h"


using namespace std;
class Game {
public:
    Game();
    ~Game();
    void run();
    int getLocation(unsigned int);
    bool running() { return isRunning; }

private:
    vector<Property*> map;
    Player* player1;
    Player* player2;
    bool isRunning;
    Player* currentPlayer;
    // WinnerDecider* wc;

};

#endif
