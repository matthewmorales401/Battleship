cmake_minimum_required(VERSION 3.13)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp player.cpp player.h connectN.cpp connectN.h board.cpp board.h move.cpp move.h)
add_compile_options(BattleShip PRIVATE -Wall -Werror)