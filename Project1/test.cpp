//#include "gtest/gtest.h"
#include "unit_test/PropertyFactory_test.hpp"
#include "unit_test/Property_test.h"
#include "unit_test/Player_test.hpp"
#include "unit_test/Card_test.hpp"
#include "unit_test/chess_test.hpp"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}