//
// Created by Alyssa on 2019-05-04.
//
#include "move.h"

connectNGame::move::move(const connectNGame::Player& moveMaker):
    moveMaker(moveMaker),
    col(0),
    row(0),
    hit(false),
    parsedSucessfuly(false) {
}

void connectNGame::move::parseInput(std::stringstream& input) {
  parsedSucessfuly = static_cast<bool>(input); //input exists, true
  input >> row >> col; //reads input as row and col
}

void connectNGame::move::make(connectNGame::Board& attackBoard,connectNGame::Board& defendBoard, std::map<int, int>& ships) {
  for (const auto& each : ships) {
    const auto& r = each.first;
    const auto& c = each.second;
    if(r==row && c==col){
      hit=true;
    }
  }
  if(hit){
    attackBoard.set(row, col, 'X');
    defendBoard.set(row, col, 'X');
    ships.clear();
  }
  else{
    attackBoard.set(row, col, 'O');
    defendBoard.set(row, col, 'O');
  }
}