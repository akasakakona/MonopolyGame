#include<iostream>
#include"Property.h"
#include"Player.h"

using namespace std;

Property::Property(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* filename)
{
	this->xpos = xpos;
	this->ypos = ypos;
	this->height = height;
	this->width = width;
	this->renderer = ren;
	objTexture = TextureManager::LoadTexture(filename, renderer);

	owner = nullptr;
	price = 0;
	rent = 0;
	mortgage = 0;
	purchasable = false;
}

Property::~Property()
{
	delete owner;
	SDL_DestroyTexture(objTexture);
}

void Property::render()
{
	SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}

void Property::update()
{
	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}
