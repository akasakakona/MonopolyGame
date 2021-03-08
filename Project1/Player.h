#ifndef __PLAYER_H
#define __PLAYER_H

#include<iostream>
#include<vector>

using namespace std;

class Property;
class Player{

public:
	Player(string n);
	~Player();

	void set_jailed(bool);
	bool get_jailed();
	void change_money(int);
	void add_property(Property* property);
	void remove_property(Property* property);
	int get_current_position();
	void change_position(int spaces);
	void set_position (int pos);
	int get_money();
	string get_name()const {return name;};
	Player* get_next()const {return next;}
	void set_next(Player* p) {next = p;}
	unsigned get_property_size(){return properties.size();}

private:
	vector<Property*> properties;
	bool isJailed;
	int money;
	int current_positon;
	string name;
	Player* next;
};

#endif //PLAYER_H