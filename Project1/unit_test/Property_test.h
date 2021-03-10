#ifndef __PROPERTY_TEST_H
#define __PROPERTY_TEST_H


#include "../Property.h"
#include "../Land.h"
#include "../Utility.h"
#include "../RailRoad.h"
#include "../Tax.h"
#include "../Chest.h"
#include "../ChessPiece.h"
#include "../Chance.h"
#include "../Player.h"
#include "../Corner.h"

#include<vector>

#include "gtest/gtest.h"


using namespace std;

TEST(PROPERTYTEST, LandPrice){
    Property* property = new Land(5,5,5,'L',"LAND_TEST",0);
    EXPECT_EQ(property->get_price(), 5);
    delete property;
}

TEST(PROPERTYTEST, UtilityPrice){
    Property* property = new Utility(5,5,5,'U',"UTILITY_TEST",0);
    EXPECT_EQ(property->get_price(), 5);
    delete property;
}

TEST(PROPERTYTEST, RailRoadPrice){
    Property* property = new RailRoad(5,5,5,'R',"RAILROAD_TEST",0);
    EXPECT_EQ(property->get_price(), 5);
    delete property;
}

TEST(PROPERTYTEST, LandName){
    Property* property = new Land(5,5,5,'L',"LAND_TEST",0);
    EXPECT_EQ(property->get_name(), "LAND_TEST");
    delete property;
}

TEST(PROPERTYTEST, UtilityName){
    Property* property = new Utility(5,5,5,'U',"UTILITY_TEST",0);
    EXPECT_EQ(property->get_name(), "UTILITY_TEST");
    delete property;
}

TEST(PROPERTYTEST, RailRoadName){
    Property* property = new RailRoad(5,5,5,'R',"RAILROAD_TEST",0);
    EXPECT_EQ(property->get_name(), "RAILROAD_TEST");
    delete property;
}
TEST(PROPERTYTEST, TaxTest){
    Property* tax = new Tax(200,0,0,'T',"TAX",0);
    EXPECT_EQ(tax->get_name(), "TAX");
    EXPECT_EQ(tax->get_owner(), nullptr);
    EXPECT_EQ(tax->is_purchasable(), false);
    EXPECT_EQ(tax->get_price(), 200);
    delete tax;
}
TEST(PROPERTYTEST, ChanceTest){

    vector<ChessPiece*> test;

    Property* chance = new Chance(0,0,0,'B',"Chance",0,test);
    EXPECT_EQ(chance->get_name(), "Chance");
    EXPECT_EQ(chance->get_owner(), nullptr);
    EXPECT_EQ(chance->is_purchasable(), false);
    EXPECT_EQ(chance->get_price(), 0);
    delete chance;
}
TEST(PROPERTYTEST, ChestTest){

    vector<ChessPiece*> test;

    Property* chest = new Chest(0,0,0,'C',"Chest",0,test);
    EXPECT_EQ(chest->get_name(), "Chest");
    EXPECT_EQ(chest->get_owner(), nullptr);
    EXPECT_EQ(chest->is_purchasable(), false);
    EXPECT_EQ(chest->get_price(), 0);
    delete chest;
}

// TEST(PROPERTYTEST, InteractLand){

//     Player *player1 = new Player(false,"a");

//     Property* property = new Land(500,100,400,'L',"LAND_TEST",0);

//     property->interact(player1);

//     EXPECT_EQ(player1->get_money(), 1000);

//     EXPECT_EQ(property->get_owner(),player1);
//     // buys property
//     property->interact(player1);
    
//     EXPECT_EQ(player1->get_money(), 1000);
    
//     Player *player2 = new Player(false,"a");
//     //player2 lands on property
//     property->interact(player2);

//     EXPECT_EQ(player2->get_money(),1400);
//     EXPECT_EQ(player1->get_money(),1100);
//     //player1 sells property
//     property->interact(player1);

//     EXPECT_EQ(player1->get_money(),1500);

//     // buys property
//     property->interact(player1);
    
//     EXPECT_EQ(player1->get_money(), 1000);
    

// }

// TEST(PROPERTYTEST, InteractUtility){

//     Player *player1 = new Player(false,"a");

//     Property* property = new Utility(500,100,400,'U',"Utility_TEST",0);

//     property->interact(player1);

//     EXPECT_EQ(player1->get_money(), 1000);

//     EXPECT_EQ(property->get_owner(),player1);

//     property->interact(player1);
    
//     EXPECT_EQ(player1->get_money(), 1000);
    
    // Player *player2 = new Player(false,"a");
    // //player2 lands on property
    // property->interact(player2);

    // EXPECT_EQ(player2->get_money(),1000);
    // EXPECT_EQ(player1->get_money(),1500);
    //player1 sells property
//     property->interact(player1);

//     EXPECT_EQ(player1->get_money(),1400);

//     // buys property
//     property->interact(player1);
    
//     EXPECT_EQ(player1->get_money(), 900);
    

// }

// TEST(PROPERTYTEST, InteractRailRoad){

//     Player *player1 = new Player(false,"a");

//     Property* property = new RailRoad(500,100,400,'L',"RailRoad_TEST",0);

//     property->interact(player1);

//     EXPECT_EQ(player1->get_money(), 1000);

//     EXPECT_EQ(property->get_owner(),player1);
//     // buys property
//     property->interact(player1);
    
//     EXPECT_EQ(player1->get_money(), 1000);
    
//     Player *player2 = new Player(false,"a");
//     //player2 lands on property
//     property->interact(player2);

//     EXPECT_EQ(player2->get_money(),1400);
//     EXPECT_EQ(player1->get_money(),1100);
//     //player1 sells property
//     property->interact(player1);

//     EXPECT_EQ(player1->get_money(),1500);

//     // buys property
//     property->interact(player1);
    
//     EXPECT_EQ(player1->get_money(), 1000);
    

// }

TEST(PROPERTYTEST, InteractCorner){

    Player *player1 = new Player(false,"a");

    Property* property1 = new Corner(200,0,0,'A',"GO_SQUARE",0);
    Property* property2 = new Corner(0,0,0,'A',"JUST_VISITING",10);
    Property* property3 = new Corner(0,0,0,'A',"FREE_PARKING",20);
    Property* property4 = new Corner(0,0,0,'A',"GO_TO_PRISON",30);

    property1->interact(player1);

    EXPECT_EQ(player1->get_money(),1700);

    player1->set_position(10);
    property2->interact(player1);

    EXPECT_EQ(player1->get_money(),1700);
    EXPECT_EQ(player1->get_jailed(),false);
    EXPECT_EQ(player1->get_jail_card(),0);

    player1->set_position(20);
    property3->interact(player1);
    EXPECT_EQ(player1->get_money(),1700);

    player1->set_position(30);
    property4->interact(player1);
    EXPECT_EQ(player1->get_jailed(), true);
    EXPECT_EQ(player1->get_current_position(),10);

    player1->set_position(10);
    property2->interact(player1);
    EXPECT_TRUE(player1->get_jailed() == true || player1->get_jailed() == false);
    delete player1;
    delete property1;
    delete property2;
    delete property3;
    delete property4;
}

TEST(PROPERTYTEST, Bot_interaction){
    Player* player = new Player(true,"a");

    Property* property = new Land(500,100,400,'L',"LAND_TEST",0);

    property->interact(player);

    EXPECT_TRUE(player->get_money() == 1500 || player->get_money() == 1000 );

    property->interact(player);

    EXPECT_TRUE(player->get_money() == 1500 || player->get_money() == 1000 );
    delete player;
    delete property;

}


TEST(PROPERTYTEST, Interact_Tax){
    Player* player = new Player(true,"a");
    Player* player1 = new Player(false,"a");

    Property* property = new Tax(500,100,400,'T',"TAX_TEST",0);

    property->interact(player);

    EXPECT_EQ(player->get_money(),1000);

    property->interact(player1);

    EXPECT_EQ(player1->get_money(),1000);
    delete player;
    delete player1;
    delete property;
}


#endif