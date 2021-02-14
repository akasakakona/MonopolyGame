#pragma once

#ifndef __BOARDOBJ_H
#define __BOARDOBJ_H

#include<iostream>
#include"SDL.h"
#include"SDL_image.h"
#include"Player.h"
using namespace std;

class BoardObj {

private:
	int xpos = 0;
	int ypos = 0;
	int height;
	int width;

	SDL_Texture* objTexture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Renderer* renderer;

public:
	BoardObj(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* filename);
	~BoardObj();

	void update();
	void render();
	virtual int get_price() ;
	virtual void set_owner(Player*);
	virtual Player* get_owner();
	virtual int get_rent() ;
	virtual int get_mortgage();

};
#endif //__BOARDOBJ_H