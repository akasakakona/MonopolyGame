#include "Button.h"


void Button::checkSelected(Mouse* mouse)
{
	if (SDL_HasIntersection(&(destRect), &(mouse->tip))) {
		selected = true;
		srcRect.x = 120;

	}
	else {
		selected = false;
		srcRect.x = 0;
	}
}

Button::Button(int xpos, int ypos, SDL_Renderer* ren, const char* filename):srcRect{xpos,ypos,120,50}
{
	renderer = ren;
	static SDL_Texture * t = IMG_LoadTexture(renderer, filename);
	objTexture = t;
	selected = false;


	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void Button::render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

void Button::setXY(int x, int y)
{
	destRect.x = x;
	destRect.y = y;
}
