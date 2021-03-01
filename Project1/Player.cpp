#include<iostream>
#include"Player.h"
#include"TextureManager.h"
#include"Property.h"
using namespace std;

Player::Player(SDL_Renderer* ren, const char* filename) {
	
	srcRect.h = 0;
	srcRect.w = 0;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = 30 + 694;
	destRect.y = 30 + 694;
	destRect.w = 40;
	destRect.h = 40;
	
	renderer = ren;
	objTexture = TextureManager::LoadTexture(filename, renderer);
	isJailed = false;
	money = 1500;
}

Player::~Player() {
	SDL_DestroyTexture(objTexture);
}

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
void Player::move() {


	//player is moving left from start
	if(destRect.y > 694  && destRect.x > 50){
		//cout << "calling move left" << endl;
		//if player is in the starting square
		if (destRect.y > 694 && destRect.x > 694) {
			destRect.x = (628+16);
		}
		//if apporaching prison square
		else if (destRect.y > 694 && destRect.x < 166) {
			destRect.x = (20);
		}
		//if not move by a constant
		else {
			destRect.x -= 66;
		}
	}
	
	//player is moving up from prison
	else if (destRect.x < 100 && destRect.y > 100) {
		//cout << "calling moving up" << endl;
		//player is starting at prison square
		if (destRect.y > 694) {
			destRect.y = (628 + 16);
		}
		// player is apporaching free parking square
		else if (destRect.y > 100 && destRect.y < 166) {
			destRect.y = 20;
		}
		//move by constant
		else {
			destRect.y -= 66;
		}
	}
	
	//player is moving left from free parking
	else if (destRect.x < 694 && destRect.y < 21) {
		//player is starting at free parking square
		if (destRect.x < 100) {
			destRect.x = 116;
		}
		//player is approaching go to jail square
		else if (destRect.x < 694 && destRect.x > 628) {
			destRect.x = 694 + 25;
		}
		else {
			destRect.x += 66;
		}
	}
	
	//player is moving down from go to jail
	else {
		//player is starting at go to jail square
		if (destRect.x > 694 && destRect.y < 100) {
			destRect.y = 116;
		}
		//player is approaching starting square
		else if (destRect.y < 694 && destRect.y > 628) {
			destRect.x = 30 + 694;
			destRect.y = 30 + 694;
		}
		else {
			destRect.y += 66;
		}
	}
	//TESTING 
	cout << destRect.x << " " << destRect.y << endl;
}


void Player::update(int spaces) {

	for (int i = 0; i < spaces; ++i) {
		move();
		render();
		SDL_RenderPresent(renderer);
		SDL_Delay(200);
	}


}

void Player::render() {
	SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}

void Player::toJail()
{
	destRect.x = 40;
	destRect.y = 694 + 16;
}
