//
// Created by Alyssa on 2019-05-04.
//

#ifndef CONNECTN__MOVE_H_
#define CONNECTN__MOVE_H_
#include "player.h"
#include "board.h"
#include <sstream>

namespace connectNGame {
class move {
 public:
  move(const Player& moveMaker);
  void parseInput(std::stringstream& input); //makes sure input is only one val
  void make(Board& attackBoard, Board& defendBoard,std::map<int, int>& ships);
 
 private:
  int col;
  int row;
  bool parsedSucessfuly;
  bool hit;
  const Player& moveMaker;
};
}
#endif //CONNECTN__MOVE_H_