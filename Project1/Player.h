#ifndef __PLAYER_H
#define __PLAYER_H

#include<iostream>
#include<vector>

using namespace std;

class Property;
class Player{

public:
	Player(bool,string);
	Player(bool);
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
	void change_jail_card(int x);
	int get_jail_card();
	bool get_is_bot();

private:
	vector<Property*> properties;
	bool isJailed;
	int money;
	string name;
	Player* next;
	bool is_bot;
	int current_positon;
	int get_out_of_jail_card = 0;
};

#endif //PLAYER_H