//to run this code
//g++ memory_leak.cpp
//valgrind --leak-check=full --track-origins=yes ./a.out

#include<iostream>

using namespace std;

#include "../Property.h"
#include "../Land.h"
#include "../Utility.h"
#include "../RailRoad.h"
#include "../PropertyFactory.h"
#include "../BoardFactory.h"
#include "../Player.h"

int main(){

    Property* property1 = new Land(5,5,5,'L',"LAND_TEST",0);
    Property* property2 = new Utility(5,5,5,'U',"UTILITY_TEST",0);
    Property* property3 = new RailRoad(5,5,5,'R',"RAILROAD_TEST",0);

    delete property1;
    delete property2;
    delete property3;

    BoardFactory *factory = new PropertyFactory("../price_rent_mortgage","../cards");
    vector<Property*> properties;
    factory->createProperty(properties);


    Player *player = new Player(true);

    player->set_position(40);
    player->add_property(properties.at(1));

    delete player;

    //manually delete the properties in the vector
    for(int i = 0; i < properties.size(); ++i){
        delete properties.at(i);
    }

    //deletes the factory but does not delete the properties
    delete factory;


    return 0;
}