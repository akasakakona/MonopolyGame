#pragma once
#ifndef __LAND_H
#define __LAND_H
#include<iostream>
#include"Property.h"
using namespace std;

class Land : public Property {
public:
	Land(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* imageName,
		int price, int rent, int mortgage, char attribute) : Property(height, width, xpos, ypos, ren, imageName) {
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = true;
	}
	~Land() {
		delete owner;
		delete objTexture;
	}
	
	virtual int get_price() {
		return this->price;
	}
	virtual void set_owner(Player* owner) {
		this->owner = owner;
	}
	virtual Player* get_owner() {
		return owner;
	}
	virtual int get_rent() {
		return this->rent;
	}
	virtual int get_mortgage() {
		return this->mortgage;
	}
	virtual void set_purchasable(bool purchasable) {
		this->purchasable = purchasable;
	}
	virtual int get_price(int dice_roll) {
		return (this->price * dice_roll);
	}
};


#endif //__LAND_H