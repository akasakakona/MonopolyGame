#pragma once

#ifndef __PLAYER_H
#define __PLAYER_H

#include<iostream>
#include<vector>
#include"SDL.h"
#include"SDL_image.h"

using namespace std;

class Property;
class Player{

public:
	Player(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* filename);
	~Player();

	void set_jailed(bool);
	bool get_jailed();
	void change_money(int);
	void add_property(Property* property);
	void remove_property(Property* property);
	void update(int x, int y);
	void render();
	SDL_Rect get_Rect() { return destRect; }




private:
	vector<Property*> properties;
	bool isJailed;
	int money;
	int xpos, ypos;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
	SDL_Texture* objTexture;

};

#endif //PLAYER_H