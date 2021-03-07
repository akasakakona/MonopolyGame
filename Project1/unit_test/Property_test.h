#ifndef __PROPERTY_TEST_H
#define __PROPERTY_TEST_H


#include "../Property.h"
#include "../Land.h"
#include "../Utility.h"
#include "../RailRoad.h"
#include "../Tax.h"
#include "../Chest.h"
#include "../ChessPiece.h"
#include "../Player.h"

#include<vector>

#include "gtest/gtest.h"


using namespace std;

TEST(PROPERTYTEST, LandPrice){
    Property* property = new Land(5,5,5,'L',"LAND_TEST",0);
    EXPECT_EQ(property->get_price(), 5);
}

TEST(PROPERTYTEST, UtilityPrice){
    Property* property = new Utility(5,5,5,'U',"UTILITY_TEST",0);
    EXPECT_EQ(property->get_price(), 5);
}

TEST(PROPERTYTEST, RailRoadPrice){
    Property* property = new RailRoad(5,5,5,'R',"RAILROAD_TEST",0);
    EXPECT_EQ(property->get_price(), 5);
}

TEST(PROPERTYTEST, LandName){
    Property* property = new Land(5,5,5,'L',"LAND_TEST",0);
    EXPECT_EQ(property->get_name(), "LAND_TEST");
}

TEST(PROPERTYTEST, UtilityName){
    Property* property = new Utility(5,5,5,'U',"UTILITY_TEST",0);
    EXPECT_EQ(property->get_name(), "UTILITY_TEST");
}

TEST(PROPERTYTEST, RailRoadName){
    Property* property = new RailRoad(5,5,5,'R',"RAILROAD_TEST",0);
    EXPECT_EQ(property->get_name(), "RAILROAD_TEST");
}
TEST(PROPERTYTEST, TaxTest){
    Property* tax = new Tax(200,0,0,'T',"TAX",0);
    EXPECT_EQ(tax->get_name(), "TAX");
    EXPECT_EQ(tax->get_owner(), nullptr);
    EXPECT_EQ(tax->is_purchasable(), false);
    EXPECT_EQ(tax->get_price(), 200);
}
TEST(PROPERTYTEST, ChanceTest){

    vector<ChessPiece*> test;

    Property* chance = new Chance(200,0,0,'B',"Chance",0,test);
    EXPECT_EQ(chance->get_name(), "Chance");
    EXPECT_EQ(chance->get_owner(), nullptr);
    EXPECT_EQ(chance->is_purchasable(), false);
    EXPECT_EQ(chance->get_price(), 200);
}
TEST(PROPERTYTEST, ChestTest){

    vector<ChessPiece*> test;

    Property* chest = new Chance(0,0,0,'C',"Chest",0,test);
    EXPECT_EQ(chest->get_name(), "Chest");
    EXPECT_EQ(chest->get_owner(), nullptr);
    EXPECT_EQ(chest->is_purchasable(), false);
    EXPECT_EQ(chest->get_price(), 0);
}

TEST(PROPERTYTEST, InteractLand){

    Player *player1 = new Player(false);

    Property* property = new Land(500,100,5,'L',"LAND_TEST",0);

    property->interact(player1);

    EXPECT_EQ(player1->get_money(), 1000);

    EXPECT_EQ(property->get_owner(),player1);

    property->interact(player1);
    
    EXPECT_EQ(player1->get_money(), 1000);

    Player *player2 = new Player(false);

    property->interact(player2);

    EXPECT_EQ(player2->get_money(),1400);
    EXPECT_EQ(player1->get_money(),1100);

}


#endif