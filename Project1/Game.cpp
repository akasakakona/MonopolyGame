#include "Game.h"
#include "WinnerDecider.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
#include "PropertyFactory.h"
using namespace std;

void Game::run(){
    isRunning = true;
    string name;
    string input;
    cout << "Hello! Welcome to Monopoly! First, tell me your name: " << endl << "Input: ";
    cin >> name;
    cin.clear();
    player1 = new Player(false, name);
    cout << "Thank you, " << player1->get_name() <<". Now, are you playing this game alone or with a friend?" << endl
    << "(a) Playing alone" << endl
    << "(b) Playing with a friend" << endl
    << "Input: ";
    cin.clear();
    cin >> input;
    if(input == "a"){
        player2 = new Player(true, "Bot");
        cout << "Again, welcome to Monopoly, " << player1->get_name() << ". "<< endl;
    }
    else{
        cout << "What is the name of the second player?" << endl << "Input: ";
        getline(cin, name);
        player2 = new Player(false, name);
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
    cin >> input;
    if(input == "a"){
        wd = new DecideByMostMoney;
    }
    else if(input == "b"){
        wd = new DecideByMostProperty;
    }
    else if(input == "c"){
        wd = new DecideByTenThousand;
    }
    else if(input == "d"){
        wd = new DecideByLastBroke;
    }
    cout << "You can now start your game. The fate has decided that " << currentPlayer->get_name() << " will go first!" << endl;
    while(isRunning){
        cout << "=============================================="<<endl;
        cout << "It is currently: " << currentPlayer->get_name() << "\'s turn!" << endl;
        if(currentPlayer->get_jailed()){
            cout << "OOF, seems like you have been jailed... Your turn skipped..." << endl;
            map.at(currentPlayer->get_current_position())->interact(currentPlayer);
            currentPlayer = currentPlayer->get_next();
            continue;
        }

        int dice1 = rand()%6 + 1;
        int dice2 = rand()%6 + 1;
        cout << currentPlayer->get_name() << " will be travelling forward " << dice1+dice2 << " steps!" << endl;
        currentPlayer->change_position(dice1+dice2);
        map.at(currentPlayer->get_current_position())->interact(currentPlayer);
        turns++;
        Player* winner = wd->evaluateWinner(this);
        if(winner){
            cout << "------------------------------------------------------------------" << endl;
            cout << "Congratuations! " << winner->get_name() << " won the game!" << endl;
            break;
        }

        currentPlayer = currentPlayer->get_next();
        cout << "------------------------------------------------------------------" << endl;

    }
}

int Game::getLocation(unsigned int l){
    if(l >= map.size()){
        currentPlayer->change_money(200);
        return l - map.size();
    }
    return l;
}

Game::Game(string filename1, string filename2){
    pf = new PropertyFactory(filename1, filename2);
    pf->createProperty(map);
}

Game::~Game(){
    delete player1;
    delete player2;
    delete wd;
    delete pf;
    for(unsigned i = 0; i < map.size(); i++){
        delete map.at(i);
    }
    delete pf;
}