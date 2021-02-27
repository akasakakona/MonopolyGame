#include"TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* ren) {
	//pass in image name for texture, use the renderer to render image onto window

	SDL_Surface* tempSurface = IMG_Load(filename);

	//create the texture
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);

	//after creating texture, we can delete the surface since texture now stores the surface
	SDL_FreeSurface(tempSurface);

	return tex;

}