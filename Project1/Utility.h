#pragma once
#ifndef __UTILITY_H
#define __UTILITY_H

#include"Property.h"

class Utility : public Property {
public:
	Utility(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* imageName,
		int price, int rent, int mortgage, char attribute) : Property(height, width, xpos, ypos, ren, imageName) {
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = true;
	}
	~Utility() {
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
};

#endif //__UTILITY_H