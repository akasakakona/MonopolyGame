#pragma once

#ifndef __PLAYER_H
#define __PLAYER_H

#include<iostream>
#include<vector>

using namespace std;

class Property;
class Player{

public:
	Player();
	~Player();

	void set_jailed(bool);
	bool get_jailed();
	void change_money(int);
	void add_property(Property* property);
	void remove_property(Property* property);

private:
	vector<Property*> properties;
	bool isJailed;
	int money;
	int xpos, ypos;
};

#endif //PLAYER_H