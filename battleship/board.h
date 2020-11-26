//
// Created by Alyssa on 2019-05-04.
//

#ifndef CONNECTN__BOARD_H_
#define CONNECTN__BOARD_H_
#include <vector>
#include <string>
#include <iostream>
#include "player.h"

namespace connectNGame {
class Board {
 public:
  using iterator = std::vector<std::string>::iterator;
  using const_iterator = std::vector<std::string>::const_iterator;
  
  explicit Board(int row, int column, char blankChar);
  //no default constructor
  int getSizeRow() const;
  int getSizeColumn() const;
  void display() const;
  bool isBlankSpace(int row, int col) const;
  bool hasBlankSpace(int row ,int col) const;
  int getRow(int col) const;
  void set(int row, int col, char val);
  bool full() const;
  
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;
  const char getBlankChar() const;
  
  const char& at(int row, int col) const;
  
  bool inBounds(int col) const;
 private:
  std::vector<std::string> boardState;
  static bool isBetween(int col, int lower, int upper);
  const char blankChar;
};
}
#endif //CONNECTN__BOARD_H_