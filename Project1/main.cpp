#include "Game.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Incorrect Usage! The proper usage should be: \n \'./ThisGame <map_config_filename> <card_config_filename>\'" << endl;
        return 0;
    }
    Game g1(argv[1], argv[2]);
    g1.run();
    return 0;
}