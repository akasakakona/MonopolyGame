#ifndef __PROPERTY_H
#define __PROPERTY_H


#include<iostream>
#include"BoardObj.h"
//#include"Player.h"

using namespace std;
//property card for board

class Player;

class Property : public BoardObj {
private:
	Player* owner;
	int price;
	int rent;
	int mortgage;

public:
	Property(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* filename, 
		     int price, int rent, int mortgage);
	~Property();

	virtual void set_owner(Player* player) override { this->owner = player; }
	virtual Player* get_owner() override { return this->owner; }
	virtual int get_price() override { return this->price; }
	virtual int get_rent() override { return this->rent; }
	virtual int get_mortgage() override { return this->mortgage; }

};

#endif //__PROPERTY_H