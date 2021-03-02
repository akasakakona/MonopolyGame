#pragma once

#ifndef __BOARD_H
#define __BOARD_H
//initiate the board objects and keep track of them in an array.
#include<iostream>
#include"Property.h"

using namespace std;

class Board {
private:
	vector<Property*> properties;
public:
	Board();
	~Board();
	

};
#endif //__BOARD_H