#include<iostream>
#include"Player.h"
#include"Property.h"
using namespace std;

Player::Player(bool is_bot, string n) {
	isJailed = false;
	money = 1500;
	current_positon = 0;
	name = n;
	next = nullptr;
    this->is_bot = is_bot;
}

Player::~Player() {}

void Player::set_jailed(bool x) {
	if (this->get_jail_card() > 0) {
		cout << "You use a get out of jail card! You're not jailed" << endl;
		this->change_jail_card(-1);
		isJailed = false;
		return;
	}
	isJailed = x;
}

bool Player::get_jailed() {
	return isJailed;
}

void Player::change_money(int x){
	money += x;
}

void Player::add_property(Property* property){

	properties.push_back(property);

}

void Player::remove_property(Property* property){
	int index = 0;
	for (unsigned int i = 0; i < properties.size(); ++i) {
		if (property->get_name() == properties.at(i)->get_name()) {
			properties.at(i)->set_owner(nullptr);
			index = i;
		}
	}
	properties.erase(properties.begin() + index);

}

void Player::set_position(int pos){
	if(pos > 40){
		while(pos > 40){
			pos -= 40;
		}
	}
	current_positon = pos;
}

void Player::change_position(int spaces){
	if((current_positon + spaces) > 39){
		current_positon = (current_positon + spaces) - 40;
	}
	else{
		current_positon += spaces;
	}
}

int Player::get_current_position(){

	return current_positon;
}

int Player::get_money(){
	return money;
}

void Player::change_jail_card(int x) {
	this->get_out_of_jail_card += x;
}

int Player::get_jail_card() {
	return this->get_out_of_jail_card;
}

bool Player::get_is_bot(){
	return this->is_bot;
}