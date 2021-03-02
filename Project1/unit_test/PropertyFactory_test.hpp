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


#endif //__PROPERTY_FACTORY_TEST