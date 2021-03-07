#ifndef __BOARD_FACTORY_H
#define __BOARD_FACTORY_H

#include<iostream>
#include<string>
#include<vector>
#include"Property.h"
#include "ChessPiece.h"
#include "ChanceCard.h"
#include "ChestCard.h"

using namespace std;

class BoardFactory {
public:
	BoardFactory() {}
	virtual ~BoardFactory(){}

	virtual void createProperty(vector<Property*> & )  = 0;
	virtual void createChessCard(vector<ChessPiece*> &chanceCards, vector<ChessPiece*> &chestCards) = 0;
};


#endif //__BOARD_FACTORY_H