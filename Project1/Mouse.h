#pragma once
#ifndef __MOUSE_H
#define __MOUSE_H
#include "TextureManager.h"
class Mouse {
public:
	Mouse(SDL_Renderer*,const char*);
	~Mouse();
	void render();
	SDL_Rect cursor, tip;

private:
	SDL_Texture* objTexture;
	SDL_Renderer* renderer;
	


};




#endif //__MOUSE_H