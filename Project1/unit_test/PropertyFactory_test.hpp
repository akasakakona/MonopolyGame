#ifndef __PROPERTY_FACTORY_TEST
#define __PROPERTY_FACTORY_TEST

#include "gtest/gtest.h"
#include <vector>
#include "../PropertyFactory.h"
#include "../BoardFactory.h"
#include "../Property.h"

using namespace std;

TEST(PROPERTYFACTORY, propertyFactoryLand_PRICE){
    BoardFactory* factory = new PropertyFactory("unit_test/land.txt");
    vector<Property* > properties;
    factory->createProperty(properties);

    EXPECT_EQ(properties.at(0)->get_price(),220 );
}

TEST(PROPERTYFACTORY, propertyFactoryLand_NAME){
    BoardFactory* factory = new PropertyFactory("unit_test/land.txt");
    vector<Property* > properties;
    factory->createProperty(properties);

    EXPECT_EQ(properties.at(0)->get_name(),"KENTUCKY_AVENUE");
}
TEST(PROPERTYFACTORY, propertyFactoryUtility_PRICE){
    BoardFactory* factory = new PropertyFactory("unit_test/land.txt");
    vector<Property* > properties;
    factory->createProperty(properties);

    EXPECT_EQ(properties.at(2)->get_rent(6),120);
}
TEST(PROPERTYFACTORY, propertyFactoryFUllTest){
    BoardFactory* factory = new PropertyFactory("unit_test/land.txt");
    vector<Property* > properties;
    factory->createProperty(properties);

    EXPECT_EQ(properties.at(0)->get_rent(6),18);
    EXPECT_EQ(properties.at(0)->get_attribute(),'L');
    EXPECT_EQ(properties.at(0)->get_name(),"KENTUCKY_AVENUE");
    EXPECT_EQ(properties.at(0)->is_purchasable(),true);
    
    EXPECT_EQ(properties.at(1)->get_rent(6),18);
    EXPECT_EQ(properties.at(1)->get_attribute(),'R');
    EXPECT_EQ(properties.at(1)->get_name(),"RAIL_ROAD");
    EXPECT_EQ(properties.at(1)->is_purchasable(),true);

    
    EXPECT_EQ(properties.at(2)->get_rent(6),120);
    EXPECT_EQ(properties.at(2)->get_attribute(),'U');
    EXPECT_EQ(properties.at(2)->get_name(),"ELECTRIC_COMPANY");
    EXPECT_EQ(properties.at(2)->is_purchasable(),true);

    EXPECT_EQ(properties.at(3)->get_rent(6),0);
    EXPECT_EQ(properties.at(3)->get_attribute(),'A');
    EXPECT_EQ(properties.at(3)->get_name(),"GO_SQUARE");
    EXPECT_EQ(properties.at(3)->is_purchasable(),false);

    EXPECT_EQ(properties.at(4)->get_rent(6),0);
    EXPECT_EQ(properties.at(4)->get_attribute(),'C');
    EXPECT_EQ(properties.at(4)->get_name(),"COMMUNITY_CHEST");
    EXPECT_EQ(properties.at(4)->is_purchasable(),false);
        
    EXPECT_EQ(properties.at(5)->get_rent(6),0);
    EXPECT_EQ(properties.at(5)->get_attribute(),'B');
    EXPECT_EQ(properties.at(5)->get_name(),"CHANCE");
    EXPECT_EQ(properties.at(5)->is_purchasable(),false);

}


#endif //__PROPERTY_FACTORY_TEST