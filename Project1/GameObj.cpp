#include "GameObj.h"
#include "TextureManager.h"
#include <iostream>
using namespace std;

GameObj::GameObj(const char* texturesheet, SDL_Renderer* ren, int x, int y) {
	renderer = ren;

	//creates object with by passing in image
	objTexture = TextureManager::LoadTexture(texturesheet, renderer);

	xpos = x;
	ypos = y;
}

GameObj::~GameObj(){/*NEED TO BE IMPLEMENTED*/ }

void GameObj::update(){

	xpos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObj::render() {
	//draws texture
	SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}