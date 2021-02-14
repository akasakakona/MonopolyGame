#ifndef __GAMEOBJ_H
#define __GAMEOBJ_H


#include "Game.h"

class GameObj {

public:
	
	GameObj(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObj();

	void update();
	void render();

private:
	
	int xpos = 0;
	int ypos = 0;

	SDL_Texture* objTexture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Renderer* renderer;

};

#endif //__GAMEOBJ_H