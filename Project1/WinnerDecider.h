#ifndef __WINNER_DECIDER__
#define __WINNER_DECIDER__
#include "Player.h"
#include "Game.h"

using namespace std;

class Game;

class WinnerDecider{
    public:
    virtual Player* evaluateWinner(Game* g) = 0;
};

class DecideByMostMoney : public WinnerDecider{
    public:
    Player* evaluateWinner(Game* g) override;
};

class DecideByMostProperty : public WinnerDecider{
    public:
    Player* evaluateWinner(Game* g) override;
};

class DecideByTenThousand : public WinnerDecider{
    public:
    Player* evaluateWinner(Game* g) override;
};

class DecideByLastBroke : public WinnerDecider{
    public:
    Player* evaluateWinner(Game* g) override;
};

#endif