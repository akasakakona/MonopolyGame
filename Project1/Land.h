
#ifndef __LAND_H
#define __LAND_H
#include<iostream>
#include"Property.h"
using namespace std;

class Land : public Property {
public:
	Land(int price, int rent, int mortgage, char attribute, string name, int ID){
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		this->purchasable = true;
		this->name = name;
		this->ID = ID;
	}
	~Land() {}
	
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
	virtual string get_name(){
		return name;
	}
	virtual char get_attribute(){
        return this->attribute;
    }
	virtual bool is_purchasable(){
		return this->purchasable;
	}

};


#endif //__LAND_H