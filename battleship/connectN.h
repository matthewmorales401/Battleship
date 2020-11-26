//
// Created by Alyssa on 2019-05-04.
//

#ifndef CONNECTN__CONNECTN_H_
#define CONNECTN__CONNECTN_H_

#include<sstream>
#include<map>
#include "move.h"

namespace connectNGame {
class connectN {
 public:
  connectN(int row, int column, std::map<std::string, int> ships);
  virtual ~connectN() = default;
  void start();
  void play();
  void print1();
  void print2();
  void determineStartingPlayer();
  move getValidMove() const;
  const Player& getCurrentPlayer() const;//cant change player
  Player& getCurrentPlayer();//can change player

  
  void changeTurn();
  void declareResults() ;
  
 private:
  int playerTurn;
  Board board;
  Board boardFire1;
  Board boardPlace1;
  Board boardFire2;
  Board boardPlace2;
  std::vector<Player> players;
  std::map<std::string, int> ships; // map of the ships from config file //[s:1]
  std::map<std::vector<int>, char> placement1; //map of the players decided location //[{1, 1}, h]
  std::map<std::vector<int>, char> placement2;
  std::map<int, int> ships1;
  std::map<int, int> ships2;
};
}
#endif //CONNECTN__CONNECTN_H_