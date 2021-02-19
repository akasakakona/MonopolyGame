#include "Mouse.h"

Mouse::Mouse(SDL_Renderer* ren, const char* filename)
{
	objTexture = TextureManager::LoadTexture(filename, ren);
	cursor = { 0,0,20,20 };
	tip = { 0,0,1,1 };
	renderer = ren;

}

void Mouse::render()
{
	tip.x = cursor.x;
	tip.y = cursor.y;
	SDL_RenderCopy(renderer, objTexture, NULL, &cursor);

}
