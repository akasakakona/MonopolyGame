#ifndef __CARD_TEST_HPP
#define __CARD_TEST_HPP


#include "gtest/gtest.h"
#include "../Chance.h"
#include "../Chest.h"
#include "../ChanceCard.h"
#include "../ChestCard.h"
#include "../ChessPiece.h"

using namespace std;

TEST(CHANCECARD, createChance){
    ChanceCard* test = new ChanceCard("This is a test", 1);
    EXPECT_EQ(test->getName(), "This is a test");
    EXPECT_EQ(test->getID(), 1);
    delete test;
}

TEST(CHESTCARD, createChest){
    ChestCard* test = new ChestCard("This is a test", 1);
    EXPECT_EQ(test->getName(), "This is a test");
    EXPECT_EQ(test->getID(), 1);
    delete test;
}

TEST(CHANCEPROPERTY, createChances){
    ChanceCard* test1 = new ChanceCard("This is a test", 1);
    vector<ChessPiece*> chanceCards;
    chanceCards.push_back(test1);

    Chance* test2 = new Chance(1,1,1,'L',"ChanceTest",1,chanceCards);
    Player* test3 = new Player(true,"a");
    test2->interact(test3);
    EXPECT_EQ(test3->get_current_position(), 24);
    delete test1;
    delete test2;
    delete test3;
}

TEST(CHESTPROPERTY, createChests){
    ChestCard* test1 = new ChestCard("This is a test", 0);
    vector<ChessPiece*> chestCards;
    chestCards.push_back(test1);

    Chest* test2 = new Chest(1,1,1,'L',"ChanceTest",1,chestCards);
    Player* test4 = new Player(true,"a");
    //cout << test4->get_money() << endl;
    test2->interact(test4);
    EXPECT_EQ(test4->get_money(), 1700);
    delete test1;
    delete test2;
    delete test4;
}

#endif