#include<iostream>
#include"Player.h"
#include"TextureManager.h"
#include"Property.h"
using namespace std;

Player::Player(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* filename) {
	this->xpos = xpos;
	this->ypos = ypos;
	srcRect.h = height;
	srcRect.w = width;
	renderer = ren;
	objTexture = TextureManager::LoadTexture(filename, renderer);
	isJailed = false;
	money = 200;
}

Player::~Player() {}

void Player::set_jailed(bool x) {
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
		if (property == properties.at(i)) {
			index = i;
		}
	}
	properties.erase(properties.begin() + index);

}
