#pragma once
#ifndef __BOARD_FACTORY_H
#define __BOARD_FACTORY_H

#include<iostream>
#include<string>
#include<vector>
#include"Property.h"

using namespace std;

class BoardFactory {
public:
	BoardFactory() {}
	virtual ~BoardFactory(){}

	virtual void createProperty(vector<Property*> & )  = 0;
	virtual void createChestPiece(vector<Property*>&) = 0;
};


#endif //__BOARD_FACTORY_H