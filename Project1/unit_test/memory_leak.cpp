#include<iostream>

using namespace std;

#include "../Property.h"
#include "../Land.h"
#include "../Utility.h"
#include "../RailRoad.h"

int main(){

    Property* property1 = new Land(5,5,5,'L',"LAND_TEST",0);
    Property* property2 = new Utility(5,5,5,'U',"UTILITY_TEST",0);
    Property* property3 = new RailRoad(5,5,5,'R',"RAILROAD_TEST",0);

    delete property1;
    delete property2;
    delete property3;


    return 0;
}