#pragma once
#ifndef __RAIL_ROAD_H
#define __RAIL_ROAD_H

#include "Property.h"

class RailRoad : public Property {
public:
	RailRoad(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* imageName,
		int price, int rent, int mortgage, char attribute) : Property(height, width, xpos, ypos, ren, imageName) {
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = true;
	}
	~RailRoad () {
		SDL_DestroyTexture(objTexture);
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


#endif //__RAIL_ROAD_H