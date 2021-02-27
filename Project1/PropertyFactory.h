#pragma once
#ifndef __PROPERTY_FACTORY_H
#define __PROPERTY_FACTORY_H

#include "BoardFactory.h"
#include "Land.h"
#include <fstream>

using namespace std;

class PropertyFactory : public BoardFactory {
public:
	PropertyFactory(string filename, SDL_Renderer* ren) {
		this->filename = filename;
		this->renderer = ren;
	}
	~PropertyFactory() {};

	virtual void createProperty(vector<Property*> &properties) {

		ifstream PROPERTY;
		
		PROPERTY.open(filename);

		if (!PROPERTY.is_open()) {
			cout << "FILE NOT OPEN!" << endl;
		}
		char attribute;
		int price;
		int rent;
		int mortgage;
		int xpos;
		int ypos;
		int height;
		int width;
		int ID;
		
		//for (int i = 0; i < 32; ++i) {
		  while(PROPERTY >> attribute){
			//PROPERTY >> attribute;
			if (attribute == 'L') {
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY >> xpos;
				PROPERTY >> ypos;
				PROPERTY >> height;
				PROPERTY >> width;
				PROPERTY >> ID;


				string image = "images/" + to_string(ID) + ".PNG";
				const char* c = image.c_str();

				Property* temp = new Land(height, width, xpos, ypos, renderer, c, price, rent, mortgage, attribute,true);
				properties.push_back(temp);
			}
			else if (attribute == 'U') {
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY >> xpos;
				PROPERTY >> ypos;
				PROPERTY >> height;
				PROPERTY >> width;
				PROPERTY >> ID;

				string image = "images/" + to_string(ID) + ".PNG";
				const char* c = image.c_str();

				Property* temp = new Land(height, width, xpos, ypos, renderer, c, price, rent, mortgage, attribute,true);
				properties.push_back(temp);
			}
			else if(attribute == 'R'){
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY >> xpos;
				PROPERTY >> ypos;
				PROPERTY >> height;
				PROPERTY >> width;
				PROPERTY >> ID;

				string image = "images/" + to_string(ID) + ".PNG";
				const char* c = image.c_str();

				Property* temp = new Land(height, width, xpos, ypos, renderer, c, price, rent, mortgage, attribute,true);
				properties.push_back(temp);
			}
			else {
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;
				PROPERTY >> xpos;
				PROPERTY >> ypos;
				PROPERTY >> height;
				PROPERTY >> width;
				PROPERTY >> ID;

				string image = "images/" + to_string(ID) + ".PNG";
				const char* c = image.c_str();

				Property* temp = new Land(height, width, xpos, ypos, renderer, c, price, rent, mortgage, attribute,false);
				properties.push_back(temp);
			}
		}

		PROPERTY.close();
	}

	virtual void createChestPiece(vector<Property*>& temp) {

	}
private:
	string filename;
	SDL_Renderer* renderer;

};


#endif //__PROPERTY_FACTORY_H