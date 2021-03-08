CMAKE_MINIMUM_REQUIRED(VERSION 3.19)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test test.cpp Player.cpp)

ADD_EXECUTABLE(monopoly main.cpp Player.cpp Game.cpp WinnerDecider.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)