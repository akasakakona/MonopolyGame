/*
create a board with 40 object --done
add property, chest, to the board
maybe a dice in this class idk
*/
#include<iostream>
#include<string>
#include"Board.h"
#include"fstream"
#include "BoardFactory.h"
#include "Property.h"
#include "PropertyFactory.h"
using namespace std;


//create the board by creating 26 building rectangle and 4 corner squares
//starting with the START square at the bottom right
Board::Board() {
	
	BoardFactory* factory = new PropertyFactory("price_rent_mortgage");
	factory->createProperty(properties);
}

Board::~Board() {
	for (unsigned int i = 0; i < properties.size(); ++i) {
		delete properties.at(i);
	}
}