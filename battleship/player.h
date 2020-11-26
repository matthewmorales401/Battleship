//
// Created by Alyssa on 2019-05-04.
//

#ifndef CONNECTN__PLAYER_H_
#define CONNECTN__PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include "board.h"

namespace connectNGame{
class Board;
class Player {
 public:
  Player();
  const std::string& getName() const;
  char getPiece() const;
  
  void AddStack(std::string str) const;
  
  void initiate();
  void askPlayerName();
  std::map<std::vector<int>, char> orientation(std::string key, int val);
 
 private:
  static std::vector<std::string>& getStack();
  std::string name;
  char piece;
  char HorV;
  int choice, r , c;
  std::map<std::vector<int>, char> shipInputs;
};
}
#endif //CONNECTN__PLAYER_H_