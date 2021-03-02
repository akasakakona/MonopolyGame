
#ifndef __RAIL_ROAD_H
#define __RAIL_ROAD_H

#include "Property.h"

class RailRoad : public Property {
public:
	RailRoad(int price, int rent, int mortgage, char attribute, string name, int ID){
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = true;
		this->name = name;
		this->ID = ID;
	}
	~RailRoad () {}

	virtual int get_price() {
		return this->price;
	}
	virtual void set_owner(Player* owner) {
		this->owner = owner;
	}
	virtual Player* get_owner() {
		return owner;
	}
	virtual int get_rent(int dice_roll) {
		return this->rent;
	}
	virtual int get_mortgage() {
		return this->mortgage;
	}
	virtual void set_purchasable(bool purchasable) {
		this->purchasable = purchasable;
	}
	virtual string get_name(){
		return name;
	}
};


#endif //__RAIL_ROAD_H