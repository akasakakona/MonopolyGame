#pragma once
#ifndef __TEXTUREMANAGER_H
#define __TEXTUREMANAGER_H

#include"Game.h"

class TextureManager {

public:

	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);


};

#endif //__TEXTUREMANAGER_H