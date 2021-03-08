#ifndef __CHANCE_H
#define __CHANCE_H

#include<iostream>
#include <time.h>
#include"Property.h"
#include"Player.h"
#include"ChessPiece.h"
using namespace std;

class Chance : public Property{
    public:
	Chance(int price, int rent, int mortgage, char attribute, string name, int ID, vector<ChessPiece*> &chanceCards){
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = false;
		this->name = name;
		this->ID = ID;
		this->chanceCards = chanceCards;
	}
    ~Chance(){}

    virtual int get_price() {
		return this->price;
	}
	virtual void set_owner(Player* owner) {
		this->owner = owner;
	}
	virtual Player* get_owner() {
		return owner;
	}
	virtual int get_rent(int dice_roll) {
		return this->rent;
	}
	virtual int get_mortgage() {
		return this->mortgage;
	}
	virtual string get_name(){
		return name;
	}
    virtual char get_attribute(){
        return this->attribute;
    }
	virtual bool is_purchasable(){
		return this->purchasable;
	}
	virtual void interact(Player* currPlayer) {
		//Generate random int
		srand(time(NULL));
		int randomInt = rand() % this->chanceCards.size();
		//Print out the card that was given
		cout << "Your card says... " << chanceCards.at(randomInt)->getName() << endl;

		if (chanceCards.at(randomInt)->getID() == 0) {
			currPlayer->set_position(0);
			cout << "You get $200" << endl;
			currPlayer->change_money(200);
		}
		else if (chanceCards.at(randomInt)->getID() == 1) {
			//Advance to Illinois Avenue
			//If player passes Go they collect $200
			if (currPlayer->get_current_position() >= 24) {
				cout << "You get $200 for passing Go" << endl;
				currPlayer->change_money(200);
			}
			currPlayer->set_position(24);
		}
		else if (chanceCards.at(randomInt)->getID() == 2) {
			//Advance to St Charles Place
			//If player passes Go they collect $200
			if (currPlayer->get_current_position() >= 11) {
				cout << "You get $200 for passing Go" << endl;
				currPlayer->change_money(200);
			}
			currPlayer->set_position(11);
		}
		else if (chanceCards.at(randomInt)->getID() == 3) {
			//Advance to nearest utility
			int currPos = currPlayer->get_current_position();
			if ( abs((12 - currPos)) < abs((28 - currPos)) ) {
				cout << "You move to Electric Company" << endl;
				currPlayer->set_position(12);
			}
			else {
				cout << "You move to Water Works" << endl;
				currPlayer->set_position(28);
			}
		}
		else if (chanceCards.at(randomInt)->getID() == 4) {
			//Advance to nearest railroad
			int currPos = currPlayer->get_current_position();
			if (currPos > 0 && currPos <= 5) {
				cout << "You move to Reading Railroad" << endl;
				currPlayer->set_position(5);
			}
			else if (currPos > 5 && currPos <= 15) {
				cout << "You move to Pennsylvania Railroad" << endl;
				currPlayer->set_position(15);
			}
			else if (currPos > 15 && currPos <= 25 ) {
				cout << "You move to B&O Railroad" << endl;
				currPlayer->set_position(25);
			}
			else {
				cout << "You move to Short Line Railroad" << endl;
				currPlayer->set_position(35);
			}
		}
		else if (chanceCards.at(randomInt)->getID() == 5) {
			//Bank pays you $50
			currPlayer->change_money(50);
		}
		else if (chanceCards.at(randomInt)->getID() == 6) {
			//Get out of jail
			cout << "Get out of jail is added to your inventory" << endl;
			currPlayer->change_jail_card(1);
		}
		else if (chanceCards.at(randomInt)->getID() == 7) {
			//Move back 3 spaces
			cout << "You move back 3 spaces..." << endl;
			currPlayer->change_position(-3);
		}
		else if (chanceCards.at(randomInt)->getID() == 8) {
			//Go to jail
			cout << "You've been jailed!" << endl;
			currPlayer->set_jailed(true);
		}
		else if (chanceCards.at(randomInt)->getID() == 9) {
			//Pay poor tax
			currPlayer->change_money(-15);
		}
		else if (chanceCards.at(randomInt)->getID() == 10) {
			//Go to Reading Railroad
			cout << "You move to Reading Railroad..." << endl;
			if (currPlayer->get_current_position() > 5) {
				cout << "You pass Go! Collect $200" << endl;
				currPlayer->change_money(200);
			}
			currPlayer->set_position(5);
		}
		else if (chanceCards.at(randomInt)->getID() == 11) {
			//Go to Boardwalk
			cout << "You move to Boardwalk..." << endl;
			currPlayer->set_position(39);
		}
		else if (chanceCards.at(randomInt)->getID() == 12) {
			//Chairman of the board
			currPlayer->change_money(-50);
		}
		else if (chanceCards.at(randomInt)->getID() == 13) {
			//Building and loan matures
			currPlayer->change_money(150);
		}
		else if (chanceCards.at(randomInt)->getID() == 14) {
			//Crossword comp
			currPlayer->change_money(100);
		}
		else if (chanceCards.at(randomInt)->getID() == 15) {
			//Win lotto
			currPlayer->change_money(100);
		}
	}

	private:
		vector<ChessPiece*> chanceCards;

};


#endif