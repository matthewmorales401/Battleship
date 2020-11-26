#include "player.h"

connectNGame::Player::Player() {
  if(getStack().empty()){
    initiate();
    AddStack("test");
  }
}
const std::string& connectNGame::Player::getName() const {
  return name;
}
char connectNGame::Player::getPiece() const {
  return piece;
}

void connectNGame::Player::AddStack(std::string str) const {
  auto& Stack = getStack();
  Stack.push_back(str);
}

std::vector<std::string>& connectNGame::Player::getStack() {
  static std::vector<std::string> Stack;
  return Stack;
}

void connectNGame::Player::initiate() {
  std::cout << "What type of game do you want to play?" << std::endl;
  std::cout << "1. Human vs Human" << std::endl;
  std::cout << "2. Human vs AI" << std::endl;
  std::cout << "3. AI vs AI" << std::endl;
  std::cout << "Your choice: ";
  std::cin >> choice;
}
void connectNGame::Player::askPlayerName() {
  std::cout << "Player " << getStack().size() << " please enter your name: ";
  std::cin >> name;
  AddStack(name);
}
std::map<std::vector<int>, char> connectNGame::Player::orientation(std::string key, int val) {
  char cstr[key.size() + 1];
  strcpy(cstr, key.c_str());
  piece = key[0];
  std::cout <<name << ", do you want to place "<< key <<" horizontally or vertically?" << std::endl;
  std::cout << "Enter h for horizontal or v for vertical"<< std::endl;
  std::cout << "Your choice: ";
  std::cin >> HorV;
  std::cout << name <<", enter the row and column you want to place "<<key<<", which is "<<val<<" long, at with a space in between row and col: ";
  std::cin >> r >> c;
  std::vector<int> cords{r,c};
  shipInputs[cords] = (HorV);
  return shipInputs;
  //print board with placement
}


