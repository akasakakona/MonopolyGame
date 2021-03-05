#ifndef __CHESTPIECEFACTORY__H
#define __CHESTPIECEFACTORY__H

#include <iostream>
#include <string>
#include <vector>
#include "ChessPiece.h"
#include "ChanceCard.h"
#include "CommunityCard.h"

using namespace std;

class ChestpieceFactory {
public:
	ChestpieceFactory(string filename) {

	}
	virtual ~ChestpieceFactory(){}

	virtual void createChance(vector<ChessPiece*>&) = 0;
	virtual void createChest(vector<ChessPiece*>&) = 0;
	virtual void createPlayer(vector<Player*>&) = 0;
};


#endif //__CHESTPIECEFACTORY__H