#ifndef __TAX_H
#define __TAX_H

#include"Property.h"
#include<string>
#include<iostream>
#include "Player.h"
#include <time.h>
using namespace std;

class Tax : public Property{
    public:
	Tax(int price, int rent, int mortgage, char attribute, string name, int ID){
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = false;
		this->name = name;
		this->ID = ID;
	}
    ~Tax(){}
    
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
	virtual void interact(Player* player){
		cout << "You have been charged with " << this->name << endl;
		player->change_money(-this->price);
		cout <<"You now have $"<<player->get_money()<<endl;
	}
};


#endif 