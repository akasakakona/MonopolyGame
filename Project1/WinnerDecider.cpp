#include "WinnerDecider.h"
#include "Game.h"
#include <iostream>
using namespace std;
Player* DecideByLastBroke::evaluateWinner(Game* g){
        if(g->getCurrentPlayer()->get_money() < 0){
            return g->getCurrentPlayer()->get_next();
        }
        else if(g->getCurrentPlayer()->get_next()->get_money() < 0){
            return g->getCurrentPlayer();
        }
        return nullptr;
}

Player* DecideByTenThousand::evaluateWinner(Game* g){
        if(g->getCurrentPlayer()->get_money() >= 10000){
            return g->getCurrentPlayer();
        }
        else if(g->getCurrentPlayer()->get_next()->get_money() >= 10000){
            return g->getCurrentPlayer()->get_next();
        }
        if(g->getCurrentPlayer()->get_money() < 0){
            cout << "==============================================" <<endl;
            cout << g->getCurrentPlayer()->get_name() << " is broke! Therefore he immediately loses the game!" << endl;
            return g->getCurrentPlayer()->get_next();
        }
        else if(g->getCurrentPlayer()->get_next()->get_money() < 0){
            cout << "==============================================" <<endl;
            cout << g->getCurrentPlayer()->get_next()->get_name() << " is broke! Therefore he immediately loses the game!" << endl;
            return g->getCurrentPlayer();
        }
        return nullptr;
}

Player* DecideByMostProperty::evaluateWinner(Game* g){
    
        if(g->getTurns() >= 50){
            if(g->getCurrentPlayer()->get_property_size() > g->getCurrentPlayer()->get_next()->get_property_size()){
                return g->getCurrentPlayer();
            }
            else if(g->getCurrentPlayer()->get_property_size() < g->getCurrentPlayer()->get_next()->get_property_size()){
                return g->getCurrentPlayer()->get_next();
            }
        }
        if(g->getCurrentPlayer()->get_money() < 0){
            cout << "==============================================" <<endl;
            cout << g->getCurrentPlayer()->get_name() << " is broke! Therefore he immediately loses the game!" << endl;
            return g->getCurrentPlayer()->get_next();
        }
        else if(g->getCurrentPlayer()->get_next()->get_money() < 0){
            cout << "==============================================" <<endl;
            cout << g->getCurrentPlayer()->get_next()->get_name() << " is broke! Therefore he immediately loses the game!" << endl;
            return g->getCurrentPlayer();
        }
        return nullptr;
}

Player* DecideByMostMoney::evaluateWinner(Game* g){
        if(g->getTurns() >= 50){
            if(g->getCurrentPlayer()->get_money() > g->getCurrentPlayer()->get_next()->get_money()){
                return g->getCurrentPlayer();
            }
            else if(g->getCurrentPlayer()->get_money() > g->getCurrentPlayer()->get_next()->get_money()){
                return g->getCurrentPlayer()->get_next();
            }
        }
        if(g->getCurrentPlayer()->get_money() < 0){
            cout << "==============================================" <<endl;
            cout << g->getCurrentPlayer()->get_name() << " is broke! Therefore he immediately loses the game!" << endl;
            return g->getCurrentPlayer()->get_next();
        }
        else if(g->getCurrentPlayer()->get_next()->get_money() < 0){
            cout << "==============================================" <<endl;
            cout << g->getCurrentPlayer()->get_next()->get_name() << " is broke! Therefore he immediately loses the game!" << endl;
            return g->getCurrentPlayer();
        }
        return nullptr;
    }
