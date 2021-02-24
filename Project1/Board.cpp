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
Board::Board(SDL_Renderer* ren) {
	
	renderer = ren;
	BoardFactory* factory = new PropertyFactory("a_p_r_m_x_y_h_w_ID.txt",renderer);
	factory->createProperty(properties);


	
}

Board::~Board() {/*NEED TO BE IMPLEMENTED*/}

void Board::board_update() {
	for (unsigned int i = 0; i < properties.size(); ++i) {
		properties.at(i)->update();
	}

}

void Board::render_board() {

	for (unsigned int i = 0; i < properties.size(); ++i) {
		properties.at(i)->render();
	}


}