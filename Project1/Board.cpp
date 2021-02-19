/*
create a board with 40 object --done
add property, chest, to the board
maybe a dice in this class idk
*/
#include<iostream>
#include<string>
#include"Board.h"
#include"fstream"
using namespace std;


//create the board by creating 26 building rectangle and 4 corner squares
//starting with the START square at the bottom right
Board::Board(SDL_Renderer* ren) {
	
	renderer = ren;

	ifstream PROPERTY;
	PROPERTY.open("price_rent_mortgage.txt");

	if (!PROPERTY.is_open()) {
		cout << "FILE NOT OPEN!!" << endl;
	}

	int x = 0;
	int y = 0;

	//price rent mortage 
	int price = 0;
	int rent = 0;
	int mortgage = 0;

	string filename = "images/";
	//adds 40 building object onto the board
	for (int i = 0; i < 40; ++i) {
		if (i == 0 ) {
			BoardObj* temp = new BoardObj(100, 100, x, y, renderer, "images/angle square.png");
			objects[i] = temp;
			x += 100;
		}
		else if(i < 10) {
			
			string tempString = filename + to_string(i) + ".png";
			const char* c = tempString.c_str();

			if (i != 2 && i != 5 && i != 8) {
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;

				BoardObj* temp = new Property(100, 66, x, y, renderer, c, price, rent, mortgage);
				objects[i] = temp;
				//cout << i << " " << price << " " << rent << " " << mortage << endl;
			}
			else {
				BoardObj* temp = new BoardObj(100, 66, x, y, renderer, c);
				objects[i] = temp;
			}
			x += 66;
		}
		else if(i == 10) {
			BoardObj* temp = new BoardObj(100, 100, x, y, renderer, "images/angle square.png");
			objects[i] = temp;
			y += 100;
		}
		else if(i < 20) {
			
			string tempString = filename + to_string(i) + ".png";
			const char* c = tempString.c_str();

			if (i != 13 && i != 15 && i != 16 && i != 18) {
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;

				BoardObj* temp = new Property(66, 100, x, y, renderer, c, price, rent, mortgage);
				objects[i] = temp;
				//cout << i << " " << price << " " << rent << " " << mortage << endl;
			}
			else {
				BoardObj* temp = new BoardObj(66, 100, x, y, renderer, c);
				objects[i] = temp;
			}
			y += 66;
		}
		else if(i == 20) {
			
			BoardObj* temp = new BoardObj(100, 100, x, y, renderer, "images/start.png");
			objects[i] = temp;
			x -= 66;
		}
		else if (i < 30) {

			string tempString = filename + to_string(i) + ".png";
			const char* c = tempString.c_str();

			if (i != 22 && i != 24 && i != 27) {
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;

				BoardObj* temp = new Property(100, 66, x, y, renderer, c,price, rent, mortgage);
				objects[i] = temp;
				cout << i << " " << price << " " << rent << " " << mortgage << endl;
			}
			else {
				BoardObj* temp = new BoardObj(100, 66, x, y, renderer, c);
				objects[i] = temp;
			}
			x -= 66;
		}
		else if(i == 30){
			x -= 34;
			BoardObj* temp = new BoardObj(100, 100, x, y, renderer, "images/jail.png");
			objects[i] = temp;
			y -= 66;
		}
		else {
			string tempString = filename + to_string(i) + ".png";
			const char* c = tempString.c_str();

			if (i != 32 && i != 35 && i != 37 ) {
				PROPERTY >> price;
				PROPERTY >> rent;
				PROPERTY >> mortgage;

				BoardObj* temp = new Property(66, 100, x, y, renderer, c, price, rent, mortgage);
				objects[i] = temp;
				//cout <<i<<" "<< price << " " << rent << " " << mortage << endl;
			}
			else {
				BoardObj* temp = new BoardObj(66, 100, x, y, renderer, c);
				objects[i] = temp;
			}
			y -= 66;
		}
		
	}

	PROPERTY.close();
}

Board::~Board() {/*NEED TO BE IMPLEMENTED*/}

void Board::board_update() {

	for (int i = 0; i < 40; ++i) {
		objects[i]->update();
	}

}

void Board::render_board() {

	for (int i = 0; i < 40; ++i) {
		objects[i]->render();
	}

}