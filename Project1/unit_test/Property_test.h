#ifndef __PROPERTY_TEST_H
#define __PROPERTY_TEST_H


#include "../Property.h"
#include "../Land.h"
#include "../Utility.h"
#include "../RailRoad.h"
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


#endif