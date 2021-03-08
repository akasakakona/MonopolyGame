#ifndef __UTILITY_H
#define __UTILITY_H

#include"Property.h"
#include<string>
#include<iostream>
#include "Player.h"
#include <time.h>
using namespace std;

class Utility : public Property {
public:
	Utility( int price, int rent, int mortgage, char attribute, string name, int ID) {
		this->price = price;
		this->rent = rent;
		this->mortgage = mortgage;
		this->attribute = attribute;
		purchasable = true;
		this->name = name;
		this->ID = ID;
	}
	~Utility() {}

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

		//if no one owns this property
		if(owner == nullptr){
			cout << "You currently have $" << player->get_money() << endl;


			//check if player is a bot
			if(player->get_is_bot()){
				if(player->get_money() < this->price){
					cout << "You do not have enough moeny to purchase this property" << endl;
				}
				else{
					int buy = rand() % 2;
					//buy the property
					if(buy == 0){
						cout<<"You have bought " << this->name << " for $"<<this->price << endl;
						
						//subtract money from player
						player->change_money(-this->price);
						this->owner = player;

						player->add_property(this);
						cout<< "You now have $" << player->get_money()<<endl;						
					}
					else{
						cout<<"You have choosen not to buy "<< this->name << endl;												
					}
				}
			}

			else{
				if(player->get_money() < this->price){
					cout << "You do not have enough moeny to purchase this property" << endl;
				}
				
				else{
					cout << "Do you wish to buy "<< this->name << " for $"<< this->price << "? (yes/no)" << endl;
					string answer;
					cin >> answer;

					while(answer != "yes" && answer != "no"){
						cout << "Please enter yes or no" << endl;
						cin >> answer;
					}

					//player buys the property
					if(answer == "yes"){
						cout<<"You have bought " << this->name << " for $"<<this->price << endl;
						
						//subtract money from player
						player->change_money(-this->price);
						this->owner = player;

						player->add_property(this);
						cout<< "You now have $" << player->get_money()<<endl;						
					}
					//player does not buy the property
					else{
						cout<<"You have choosen not to buy "<< this->name << endl;
					}
				}
			}
		}
		
		//if the player is not the owner of this property
		else if(owner != player){

			//current player pays the owner

			int random = rand() % 12 + 1;
			
			int a = get_rent(random);

			cout<<"You have landed on a property that is not own by you, you will have to pay $" << a << endl;

			player->change_money(-a);
			owner->change_money(a);

		}
		else{
			cout << "You are the current owner of " << this->name << endl;

			if(player->get_is_bot() == false){

				cout << "Do you wish to sell your property? (yes/no)" << endl;

				string answer;
				cin >> answer;

				while(answer != "yes" && answer != "no"){
					cout << "Please enter yes or no" << endl;
					cin >> answer;
				}

				if(answer == "yes"){
					cout << "You have just sold " << this->name << endl;
					player->change_money(this->mortgage);
					this->owner = nullptr;

					cout << "You now have $" << player->get_money() << endl;
				}
				else{
					cout << "You are still the current owner of " << this->name << endl;
				}
			}
		}
	}
};

#endif //__UTILITY_H