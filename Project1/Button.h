#pragma once
#ifndef __BUTTON_H
#define __BUTTON_H
#include "TextureManager.h"
#include "Mouse.h"


using namespace std;

class Button {
private:
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
	bool selected;
	int dice1, dice2;
	
public:
	Button(int xpos, int ypos, SDL_Renderer* ren, const char* filename);
	~Button();
	void render();
	void setXY(int x, int y);
	void checkSelected(Mouse* mouse);
	bool get_selected() { return selected; }
	
	//roll 2 dice and return the dice value
	int roll_dice();

	// return true if the 2 dices are equal
	bool isEqual();

};
#endif //__BUTTON_H