#pragma once

#ifndef __BOARD_H
#define __BOARD_H
//initiate the board objects and keep track of them in an array.
#include<iostream>
//#include"BoardObj.h"
#include"Property.h"

using namespace std;

class Board {
private:
	
	SDL_Renderer* renderer;
	BoardObj* objects[40];

public:
	Board(SDL_Renderer* ren);
	~Board();
	
	//BoardObj* get_BoardObj();

	void board_update();
	void render_board();

};
#endif //__BOARD_H