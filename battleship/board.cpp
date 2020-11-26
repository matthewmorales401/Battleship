//
// Created by Alyssa on 2019-05-04.
//

#include "board.h"

connectNGame::Board::Board(int row, int column, char blankChar):
    boardState(row, std::string(column, blankChar)), //number of rows consisting of columns large
    // if (2,3, '0') then boardstate=[000,000]
    blankChar(blankChar) {
}

int connectNGame::Board::getSizeColumn() const {
  return boardState.at(0).size(); //size of the string at index 0
}
int connectNGame::Board::getSizeRow() const {
  return boardState.size(); //size of the vector
}
void connectNGame::Board::display() const {
  std::cout << "  ";
  for (int i = 0; i < getSizeColumn(); ++i) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  int rowIndex = 0;
  for (const auto& row : boardState) {
    std::cout << rowIndex << ' ';
    for(const auto& elem : row){
      std::cout << elem << ' ';
    }
    rowIndex++;
    std::cout << std::endl;
  }
}
bool connectNGame::Board::inBounds(int col) const {
  return isBetween(col, 0, getSizeColumn()-1);
}
bool connectNGame::Board::isBetween(int col, int lower, int upper) {
  return col>=lower && col<=upper;
}
bool connectNGame::Board::hasBlankSpace(int row, int col) const {
  for (int i = 0; i<=getSizeRow()-1; i++) {
    if (boardState.at(i).at(col) == blankChar) {
      return true;
    }
  }
  return false;
}
int connectNGame::Board::getRow(int col) const{
  for (int i = getSizeRow()-1; i>=0; --i) {
    if (boardState.at(i).at(col) == blankChar) {
      return i;
    }
  }
  return -1;
}
void connectNGame::Board::set(int row, int col, char val) {
  boardState.at(row).at(col)=val;
} 


connectNGame::Board::iterator connectNGame::Board::begin() {
  return boardState.begin();
}
connectNGame::Board::iterator connectNGame::Board::end() {
  return boardState.end();
}
connectNGame::Board::const_iterator connectNGame::Board::cbegin() const {
  return boardState.cbegin();
}
connectNGame::Board::const_iterator connectNGame::Board::cend() const {
  return boardState.cend();
}
const char connectNGame::Board::getBlankChar() const {
  return blankChar;
}
const char& connectNGame::Board::at(int row, int col) const{
  return boardState.at(row).at(col);
}
bool connectNGame::Board::isBlankSpace(int row, int col) const {
  return boardState.at(row).at(col) == blankChar;
}
bool connectNGame::Board::full() const {
  for(auto rowItr = cbegin(); rowItr != cend(); ++rowItr){
    for(int row=0; row < getSizeRow(); ++row){
      for (int col=0; col < getSizeColumn(); ++col){
        if(isBlankSpace(row, col)){
          return false;
        }
      }
    }
  }
  return true;
}