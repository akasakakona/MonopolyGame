#ifndef __PROPERTY_H
#define __PROPERTY_H


#include<iostream>

using namespace std;
//property card for board

class Player;

class Property{
protected:
	char attribute;
	Player* owner = nullptr;
	int price;
	int rent;
	int mortgage;
	bool purchasable = false;
	string name;
	int ID;

public:
	virtual ~Property() = default;

	virtual int get_price() = 0;
	virtual void set_owner(Player*) = 0;
	virtual Player* get_owner() = 0;
	virtual int get_rent(int) = 0;
	virtual int get_mortgage() = 0;
	virtual string get_name() = 0;
	virtual char get_attribute() = 0;
	virtual bool is_purchasable() = 0;
	virtual void interact(Player*) = 0;


};

#endif //__PROPERTY_H