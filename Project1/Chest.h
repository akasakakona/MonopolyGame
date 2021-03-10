#ifndef __CHEST_H
#define __CHEST_H

#include<iostream>
#include"Property.h"
#include"ChessPiece.h"
using namespace std;

class Chest : public Property{
    public:
	Chest(int price, int rent, int mortgage, char attribute, string name, int ID, vector<ChessPiece*> &chestCards){
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = false;
		this->name = name;
		this->ID = ID;
		this->chestCards = chestCards;
	}
    ~Chest(){}
    
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
		int randomInt = rand() % this->chestCards.size();
		//Print out the card that was given
		cout << "Your card says... " << chestCards.at(randomInt)->getName() << endl;

		if (chestCards.at(randomInt)->getID() == 0) {
			currPlayer->set_position(0);
			cout << "You get $200" << endl;
			currPlayer->change_money(200);
		}
		else if (chestCards.at(randomInt)->getID() == 1) {
			//Collect $200
			currPlayer->change_money(200);
		}
		else if (chestCards.at(randomInt)->getID() == 2) {
			//Doctor fees
			currPlayer->change_money(-50);
		}
		else if (chestCards.at(randomInt)->getID() == 3) {
			//Stonks
			currPlayer->change_money(50);
		}
		else if (chestCards.at(randomInt)->getID() == 4) {
			//Get out of jail
			cout << "Get out of jail is added to your inventory" << endl;
			currPlayer->change_jail_card(1);
		}
		else if (chestCards.at(randomInt)->getID() == 5) {
			//Go to jail
			cout << "You've been jailed!" << endl;
			currPlayer->set_jailed(true);
			currPlayer->set_position(10);
		}
		else if (chestCards.at(randomInt)->getID() == 6) {
			//Opera
			currPlayer->change_money(50);
		}
		else if (chestCards.at(randomInt)->getID() == 7) {
			//Holiday fund
			currPlayer->change_money(100);
		}
		else if (chestCards.at(randomInt)->getID() == 8) {
			//Income tax refund
			currPlayer->change_money(20);
		}
		else if (chestCards.at(randomInt)->getID() == 9) {
			//Birthday
			currPlayer->change_money(10);
		}
		else if (chestCards.at(randomInt)->getID() == 10) {
			//Life insurance
			currPlayer->change_money(100);
		}
		else if (chestCards.at(randomInt)->getID() == 11) {
			//Hospital fees
			currPlayer->change_money(-50);
		}
		else if (chestCards.at(randomInt)->getID() == 12) {
			//School fees
			currPlayer->change_money(-50);
		}
		else if (chestCards.at(randomInt)->getID() == 13) {
			//Consulting fees
			currPlayer->change_money(50);
		}
		else if (chestCards.at(randomInt)->getID() == 14) {
			//Beauty contest
			currPlayer->change_money(10);
		}
		else if (chestCards.at(randomInt)->getID() == 15) {
			//Inherit 100
			currPlayer->change_money(100);
		}
	}

	private: 
		vector<ChessPiece*> chestCards;
};


#endif 