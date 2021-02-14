#include<iostream>
#include"Property.h"
#include"Player.h"

using namespace std;

Property::Property(int height, int width, int xpos, int ypos, SDL_Renderer* ren, const char* filename,
	               int price, int rent, int mortage) : BoardObj(height, width, xpos, ypos, ren, filename) {
	owner = nullptr;
	this->price = price;
	this->rent = rent;
	this->mortage = mortage;
}

Property::~Property() {
	delete owner;
}

