#ifndef __PLAYER_TEST_HPP
#define __PLAYER_TEST_HPP


#include "gtest/gtest.h"
#include "../Player.h"

using namespace std;

TEST(PLAYERTEST, playerInit){
    Player* player1 = new Player();

    EXPECT_EQ(player1->get_money(), 1500);
    EXPECT_EQ(player1->get_current_position(), 0);
    EXPECT_EQ(player1->get_jailed(), false);
}

TEST(PLAYERTEST, playerMovement){
    Player* player1 = new Player();

    EXPECT_EQ(player1->get_current_position(), 0);
    
    player1->change_position(10);
    EXPECT_EQ(player1->get_current_position(), 10);

    player1->set_position(39);
    EXPECT_EQ(player1->get_current_position(), 39);

    player1->change_position(6);
    EXPECT_EQ(player1->get_current_position(), 5);
}

TEST(PLAYERTEST, playerSetPosition){
    Player* player1 = new Player();

    player1->set_position(41);
    EXPECT_EQ(player1->get_current_position(), 1);

    player1->set_position(100);
    EXPECT_EQ(player1->get_current_position(), 20);
    
}
#endif