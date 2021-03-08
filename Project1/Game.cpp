#include "Game.h"

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void Game::run(){
    isRunning = true;
    string name;
    string input;
    cout << "Hello! Welcome to Monopoly! First, tell me your name: " << endl << "Input: ";
    getline(cin, name);
    player1 = new Player(name);
    cout << "Thank you, " << player1->get_name() <<". Now, are you playing this game alone or with a friend?" << endl
    << "(a) Playing alone" << endl
    << "(b) Playing with a friend" << endl
    << "Input: ";
    if(input == "a"){
        //player2 = new Bot();
        cout << "Again, welcome to Monopoly, " << player1->get_name() << ". "<< endl;
    }
    else{
        cout << "What is the name of the second player?" << endl << "Input: ";
        getline(cin, name);
        player2 = new Player(name);
        cout << "Welcome to Monopoly, " << player1->get_name() << " and " << player2->get_name() << ". " << endl;
    }
    srand(time(NULL));
    int randChoice = rand()%2;
    if(randChoice == 0){
        currentPlayer = player1;
        currentPlayer->set_next(player2);
        player2->set_next(player1);
    }
    else{
        currentPlayer = player2;
        currentPlayer->set_next(player1);
        player1->set_next(player2);
    }
    cout << "Before we start, how would you like to win this game? You can choose from a list of rules below:" << endl
    << "(a) Most money wins" << endl
    << "(b) Most property wins" << endl
    << "(c) First to save up $10000 wins" << endl
    << "(d) The last to not broke" << endl;
    cin.clear();
    cin >> input;
    if(input == "a"){
        //wc = ;
    }
    else if(input == "b"){
        //wc = ;
    }
    else if(input == "c"){
        //wc = ;
    }
    else if(input == "d"){
        //wc = ;
    }
    cout << "You can now start your game. The fate has decided that " << currentPlayer->get_name() << " will go first!" << endl;
    while(isRunning){
        cout << "It is currently: " << currentPlayer->get_name() << "\'s turn!" << endl;
        if(currentPlayer->get_jailed()){
            cout << "OOF, seems like you have been jailed... Your turn skipped..." << endl;
            currentPlayer = currentPlayer->get_next();
            continue;
        }
        randChoice = rand()%6 + 1;
        cout << currentPlayer->get_name() << " will be travelling forward " << randChoice << " steps!" << endl;
        // map.at(getLocation(currentPlayer->get_current_position() + randChoice))->interact();
        currentPlayer->change_position(getLocation(currentPlayer->get_current_position() + randChoice));
    }
}

int Game::getLocation(unsigned int l){
    if(l >= map.size()){
        currentPlayer->change_money(200);
        return l - map.size();
    }
    return l;
}

Game::~Game(){
    delete player1;
    delete player2;
}