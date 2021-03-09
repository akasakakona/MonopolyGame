#ifndef __CHEST_TEST_HPP
#define __CHEST_TEST_HPP


#include "gtest/gtest.h"
#include <vector>
#include "../PropertyFactory.h"
#include "../BoardFactory.h"
#include "../Property.h"

TEST(CHANCE_TEST, chanceInteract) {
    BoardFactory *factory = new PropertyFactory("unit_test/land.txt","unit_test/card_test.txt");
    vector<ChessPiece*> chances;
    vector<ChessPiece*> chests;

    factory->createChessCard(chances, chests);

    Property *chance = new Chance(0,0,0,'C',"CHANCE",5,chances);

    Player* player = new Player(false,"test");

    chance->interact(player);

    EXPECT_EQ(player->get_money(),1700);

}

#endif 