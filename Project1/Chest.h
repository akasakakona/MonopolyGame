#ifndef __CHEST_H
#define __CHEST_H

#include<iostream>
#include"Property.h"
using namespace std;

class Chest : public Property{
    public:
	Chest(int price, int rent, int mortgage, char attribute, string name, int ID){
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = false;
		this->name = name;
		this->ID = ID;
	}
    ~Chest(){}
    
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
};


#endif 