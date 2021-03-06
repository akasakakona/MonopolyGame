#ifndef __CORNER_H
#define __CORNER_H

#include"Property.h"
#include<string>
#include<iostream>
#include "Player.h"
#include <time.h>
using namespace std;

class Corner : public Property {
public:
	Corner( int price, int rent, int mortgage, char attribute, string name, int ID) {
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = false;
		this->name = name;
		this->ID = ID;
	}
	~Corner() {}

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
		return this->rent * dice_roll;
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
	virtual void interact(Player* player){

		srand(time(NULL));
		//player is at go square
		if(player->get_current_position() == 0){
			cout<<"You have arrived at Go"<<endl;
			player->change_money(200);
		}
		//player is at go to jail square
		else if(player->get_current_position() == 30){

			cout<<"You have arrived at go to jail square"<< endl;

			//check if player has a get out of jail card
			if(player->get_jail_card() > 0){
				cout<<"Get out of jail card used"<<endl;
				player->change_jail_card(-1);
			}
			//player goes to jail
			else{

				cout <<"You have been sent to jail" << endl;
				player->set_position(10);
				player->set_jailed(true);
			}
		}
		else if(player->get_current_position() == 20){
			cout<<"You have arrived at Free Parking"<<endl;
		}
		else{
			//if player is in jail
			if(player->get_current_position() == 10 && player->get_jailed()){
				int a = rand() % 6 + 1;
				int b = rand() % 6 + 1;
				
				cout << "You have rolled a " << a << " and a " << b <<endl;
				if(a == b){
					cout << "You have rolled a double which means you are free!" << endl;
					player->set_jailed(false);
				}
				else{
					if(player->get_is_bot() == false){
						cout << "You are still in jail since you did not roll a double" << endl;
						cout << "Do you wish to pay $50 to get out of jail? (yes/no)" << endl;

						string answer;
						cin >> answer;

						while(answer != "yes" && answer != "no"){
							cin >> answer;
						}

						if(answer == "yes" && player->get_money() >50){
							cout<<"You are free, and is no longer in jail!" << endl;
							player->change_money(-50);
							player->set_jailed(false);
						}
						else if (answer == "no"){
							cout<<"You are still in jail, please wait till next turn"<<endl;
						}
						else{
							cout<<"You do not have enough money for bail!"<<endl;
							cout<<"You are still in jail, please wait till next turn"<<endl;
						}
					}

				} 
			}
			else{
				cout << "You are just visiting jail" << endl;
			}
		}


		
	}
};

#endif //__CORNER_H