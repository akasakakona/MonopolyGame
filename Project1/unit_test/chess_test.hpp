#ifndef __CHEST_TEST_HPP
#define __CHEST_TEST_HPP


#include "gtest/gtest.h"
#include <vector>
#include "../PropertyFactory.h"
#include "../Property.h"

TEST(CHANCE_TEST, chanceInteract) {
    PropertyFactory *factory = new PropertyFactory("unit_test/land.txt","unit_test/card_test.txt");
    vector<ChessPiece*> chances;
    vector<ChessPiece*> chests;

    factory->createChessCard(chances, chests);

    Property *chance = new Chance(0,0,0,'C',"CHANCE",5,chances);

    Player* player = new Player(false,"test");

    chance->interact(player);

    EXPECT_EQ(player->get_money(),1700);
    delete factory;
    delete chance;
    delete player;
    for(unsigned i = 0; i < chances.size(); i++){
        delete chances.at(i);
    }
    for(unsigned i = 0; i < chests.size(); i++){
        delete chests.at(i);
    }

}

#endif 