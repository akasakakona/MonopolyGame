#include "Button.h"
#include <time.h>
using namespace std;

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


int Button::roll_dice()
{
	srand(time(NULL));
	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;
	return dice1 + dice2;
}

bool Button::isEqual()
{
	if (dice1 == dice2) {
		return true;
	}
	return false;
}

Button::Button(int xpos, int ypos, SDL_Renderer* ren, const char* filename):srcRect{xpos,ypos,120,50}
{
	renderer = ren;
	static SDL_Texture * t = IMG_LoadTexture(renderer, filename);
	objTexture = t;
	selected = false;
	dice1 = 0;
	dice2 = 0;


	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

Button::~Button()
{
	SDL_DestroyTexture(objTexture);
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
