#ifndef __PROPERTY_H
#define __PROPERTY_H


#include<iostream>
#include"TextureManager.h"

using namespace std;
//property card for board

class Player;

class Property{
protected:
	char attribute;
	Player* owner;
	int price;
	int rent;
	int mortgage;
	bool purchasable;

	int xpos = 0;
	int ypos = 0;
	int height;
	int width;

	SDL_Texture* objTexture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Renderer* renderer;

public:
	Property(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* filename);
	~Property();

	void render();
	void update();
	SDL_Rect get_Rect() { return destRect; }

	virtual int get_price() = 0;
	virtual void set_owner(Player*) = 0;
	virtual Player* get_owner() = 0;
	virtual int get_rent() = 0;
	virtual int get_mortgage() = 0;
	virtual void set_purchasable(bool) = 0;
	virtual int get_price(int) = 0;


};

#endif //__PROPERTY_H