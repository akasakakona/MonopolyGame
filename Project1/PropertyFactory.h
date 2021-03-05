
#ifndef __PROPERTY_FACTORY_H
#define __PROPERTY_FACTORY_H

#include "BoardFactory.h"
#include "Land.h"
#include "Utility.h"
#include "RailRoad.h"
#include "Chance.h"
#include "Chest.h"
#include "Tax.h"
#include <fstream>

using namespace std;

class PropertyFactory : public BoardFactory {
public:
	PropertyFactory(string filename) {
		this->filename = filename;
	}
	~PropertyFactory() {};

	virtual void createProperty(vector<Property*> &properties) {

		ifstream PROPERTY;
		
		PROPERTY.open(filename);

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

				Property* temp = new Land(price, rent, mortgage, attribute,name,ID);
				properties.push_back(temp);
			}
			else if(attribute == 'C'){
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY>>name;
				PROPERTY >> ID;

				Property* temp = new Chest(price, rent, mortgage, attribute,name,ID);
				properties.push_back(temp);
			}
			else if(attribute == 'B'){
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY>>name;
				PROPERTY >> ID;

				Property* temp = new Chance(price, rent, mortgage, attribute,name,ID);
				properties.push_back(temp);
			}

		}

		PROPERTY.close();
	}

	virtual void createChestPiece(vector<Property*>& temp) {

	}
private:
	string filename;

};


#endif //__PROPERTY_FACTORY_H