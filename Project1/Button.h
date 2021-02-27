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
	
public:
	Button(int xpos, int ypos, SDL_Renderer* ren, const char* filename);
	void render();
	void setXY(int x, int y);
	void checkSelected(Mouse* mouse);
	bool get_selected() { return selected; }

};
#endif //__BUTTON_H