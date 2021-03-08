#ifndef __CHESSPIECEFACTORY__H
#define __CHESSPIECEFACTORY__H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ChessPiece.h"
#include "ChanceCard.h"
#include "ChestCard.h"

using namespace std;

class ChesspieceFactory {
public:
	ChesspieceFactory(string filename) {
		this->filename = filename;
	}
	virtual ~ChesspieceFactory(){}

	virtual void createCards(vector<ChessPiece*> &chanceCards, vector<ChessPiece*> &chestCards) {
		ifstream CARDS;

		CARDS.open(this->filename);

		if (!CARDS.is_open()) {
			cout << "FILE NOT OPEN" << endl;
		}

		//C is for Chance. B is for Community Chest Cards
		char type;
		//String for description
		string descript;
		//ID
		int cardID;

		while (CARDS >> type) {
			if (type == 'C') {
				CARDS >> descript;
				CARDS >> cardID;

				ChessPiece* temp = new ChanceCard(descript, cardID);
				chanceCards.push_back(temp);
			}
			else if (type == 'B') {
				CARDS >> descript;
				CARDS >> cardID;

				ChessPiece* temp = new ChestCard(descript, cardID);
				chestCards.push_back(temp);
			}
		}
		CARDS.close();
	}

	virtual void createPlayer(vector<Player*>&);

private:
	string filename;
};


#endif //__CHESSPIECEFACTORY__H