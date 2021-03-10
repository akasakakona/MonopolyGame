#ifndef __GAME_H__
#define __GAME_H__

#include<iostream>
#include<string>
#include <vector>
#include "Player.h"
#include "Property.h"
#include "Game.h"
#include "PropertyFactory.h"
// #include "ChanceCard.h"
// #include "CommunityCard.h"

class WinnerDecider;

using namespace std;
class Game {
public:
    Game(string filename1, string filename2);
    ~Game();
    void run();
    int getLocation(unsigned int);
    bool running() { return isRunning; }
    unsigned int getTurns() const {return turns;}
    Player* getCurrentPlayer() const {return currentPlayer;}

private:
    vector<Property*> map;
    Player* player1;
    Player* player2;
    bool isRunning;
    Player* currentPlayer;
    WinnerDecider* wd;
    unsigned int turns;
    PropertyFactory* pf;
};

#endif
