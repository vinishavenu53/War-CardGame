cmake_minimum_required(VERSION 3.9)
project(War)

set(CMAKE_CXX_STANDARD 11)

add_executable(War Card.cpp Card.h Deck.cpp Deck.h Hand.cpp Hand.h playWar.cpp)