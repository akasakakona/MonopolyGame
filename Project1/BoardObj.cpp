

#include<iostream>
#include"BoardObj.h"
#include"TextureManager.h"

using namespace std;

BoardObj::BoardObj(int h, int w, int x, int y, SDL_Renderer* ren, const char* filename) {
	xpos = x;
	ypos = y;
	height = h;
	width = w;
	renderer = ren;
	objTexture = TextureManager::LoadTexture(filename, renderer);

}

BoardObj::~BoardObj() {/*NEED TO BE IMPLEMENTED*/}

void BoardObj::update() {

	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

}

void BoardObj::render() {
	SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}
int BoardObj::get_price() { return 0; }
 void BoardObj::set_owner(Player*owner){}
 Player* BoardObj::get_owner() { return nullptr; }
 int BoardObj::get_rent() { return 0; }
 int BoardObj::get_mortgage() { return 0; }