
#ifndef __PROPERTY_FACTORY_H
#define __PROPERTY_FACTORY_H

#include "BoardFactory.h"
#include "Land.h"
#include "Utility.h"
#include "RailRoad.h"
#include "Chance.h"
#include "Chest.h"
#include "Tax.h"
#include "Corner.h"
#include "ChessPiece.h"
#include "ChanceCard.h"
#include "ChestCard.h"
#include <fstream>

using namespace std;

class PropertyFactory : public BoardFactory {
public:
	PropertyFactory(string filename1, string filename2) {
		this->filename1 = filename1;
		this->filename2 = filename2;
	}
	~PropertyFactory() {
		for(unsigned int i = 0; i < chanceCards.size(); ++i){
			delete chanceCards.at(i);
		}
		for(unsigned int i = 0; i < chestCards.size(); ++i){
			delete chestCards.at(i);
		}
	};

	virtual void createProperty(vector<Property*> &properties) {

		createChessCard(this->chanceCards,this->chestCards);

		ifstream PROPERTY;
		
		PROPERTY.open(filename1);

		if (!PROPERTY.is_open()) {
			cout << "FILE NOT OPEN!" << endl;
		}
		//what kind of property it is. L = land, U = utility, R = railroad, A = corner
		char attribute;
		//price to purchase
		int price;
		//price player have to pay after landing on it
		int rent;
		//price of property if player wants to sell
		int mortgage;
		//name of the property
		string name;
		//ID of each property starting from 0, go sqaure has ID 0
		int ID;
		while(PROPERTY >> attribute){
			if (attribute == 'L') {

				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY >> name;
				PROPERTY >> ID;

				Property* temp = new Land(price, rent, mortgage, attribute,name,ID);
				properties.push_back(temp);
			}
			else if (attribute == 'U') {


				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY>>name;
				PROPERTY >> ID;


				Property* temp = new Utility(price, rent, mortgage, attribute,name,ID);
				properties.push_back(temp);
			}
			else if(attribute == 'R'){

				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY>>name;
				PROPERTY >> ID;

				Property* temp = new RailRoad(price, rent, mortgage, attribute,name,ID);
				properties.push_back(temp);
			}
			else if (attribute == 'A'){

				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY>>name;
				PROPERTY >> ID;

				Property* temp = new Corner(price, rent, mortgage, attribute,name,ID);
				properties.push_back(temp);
			}
			else if(attribute == 'C'){

				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY>>name;
				PROPERTY >> ID;

				Property* temp = new Chest(price, rent, mortgage, attribute,name,ID,chestCards);
				properties.push_back(temp);
			}
			else if(attribute == 'B'){

				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY>>name;
				PROPERTY >> ID;

				Property* temp = new Chance(price, rent, mortgage, attribute,name,ID,chanceCards);
				properties.push_back(temp);
			}
			else if(attribute == 'T'){

				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY>>name;
				PROPERTY >> ID;

				Property* temp = new Tax(price, rent, mortgage, attribute,name,ID);
				properties.push_back(temp);
			}

		}
		PROPERTY.close();
	}

virtual void createChessCard(vector<ChessPiece*> &chanceCards, vector<ChessPiece*> &chestCards){
		ifstream CARDS;

		CARDS.open(this->filename2);

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
private:
	string filename1;
	string filename2;
	vector<ChessPiece*> chanceCards;
	vector<ChessPiece*> chestCards;


};


#endif //__PROPERTY_FACTORY_H