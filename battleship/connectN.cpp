#include "connectN.h"

connectNGame::connectN::connectN(int row, int column, std::map<std::string, int> ships) :
    ships(ships),
    playerTurn(-1), //start off playerTurn with a arbitrary val
    board(row, column, '*'),
    boardFire1(row, column, '*'), boardPlace1(row, column, '*'),
    boardFire2(row, column, '*'), boardPlace2(row, column, '*'),
    players(2){
}
void connectNGame::connectN::start(){
  determineStartingPlayer();
  getCurrentPlayer().askPlayerName();
  boardPlace1.display();
  for (const auto& each : ships){
    const auto& key = each.first;
    const auto& val = each.second;
    std::map<std::vector<int>, char> temp = getCurrentPlayer().orientation(key, val);
    for (const auto& i : temp) {
      const auto& k = i.first;
      const auto& v = i.second;
      boardPlace1.set(k[0], k[1], getCurrentPlayer().getPiece() );
      placement1.insert(std::pair<std::vector<int>, char>(k, v));
      for (const auto& x : placement1) {
        const auto& s = x.first;
        ships1.insert(std::pair<int, int>(s[0], s[1]));
      }
      boardPlace1.display();
    }
  }
  changeTurn();
  getCurrentPlayer().askPlayerName();
  boardPlace2.display();
  for (const auto& each : ships){
    const auto& key = each.first;
    const auto& val = each.second;
    std::map<std::vector<int>, char> temp = getCurrentPlayer().orientation(key, val);
    for (const auto& i : temp) {
      const auto& k = i.first;
      const auto& v = i.second;
      boardPlace2.set(k[0], k[1], getCurrentPlayer().getPiece() );
      placement2.insert(std::pair<std::vector<int>, char>(k, v));
      for (const auto& x : placement2) {
        const auto& s = x.first;
        ships2.insert(std::pair<int, int>(s[0], s[1]));
      }
      boardPlace2.display();
    }
  }
}

void connectNGame::connectN::play() {
  determineStartingPlayer();
  do{
    while (playerTurn == 0) {
      print1();
      move move = getValidMove();   //ask for move
      move.make(boardFire1, boardPlace2, ships2);
      print1();
      if (ships2.empty()) {
        declareResults();
        break;
      }
      std::cout << "Missed."<<std::endl;
      std::cout << std::endl;
      changeTurn(); //switch turn
    }
    while (playerTurn == 1) {
      print2();
      move m = getValidMove();   //ask for move
      m.make(boardFire2, boardPlace1, ships1);
      print2();
      if (ships1.empty()) {
        declareResults();
        break;
      }
      std::cout << "Missed." << std::endl;
      std::cout << std::endl;
      changeTurn(); //switch turn
    }
  }while(!ships2.empty() && !ships1.empty());
}


void connectNGame::connectN::determineStartingPlayer() {
  playerTurn=0;
}
connectNGame::move connectNGame::connectN::getValidMove() const{
  move playerMove(getCurrentPlayer());//calls const version
  std::cout <<getCurrentPlayer().getName()<< ", where would you like to fire?"<<std::endl;
  std::cout <<"Enter your attack coordinate in the form row col: ";
  std::string line;
  do {
    getline(std::cin, line);
  } while (line.empty());
  std::stringstream userIn(line);
  playerMove.parseInput(userIn);
  return playerMove;
}
const connectNGame::Player& connectNGame::connectN::getCurrentPlayer() const {
  return players.at(playerTurn);
}
connectNGame::Player& connectNGame::connectN::getCurrentPlayer() {
  return players.at(playerTurn);
}

void connectNGame::connectN::changeTurn() {
  playerTurn = (playerTurn +1) % players.size();
}
void connectNGame::connectN::declareResults() {
  std::cout<<getCurrentPlayer().getName()<< " hit ";
  changeTurn();
  std::cout<<getCurrentPlayer().getName()<< "'s ";
  std::cout<<getCurrentPlayer().getPiece()<<"!"<<std::endl;
  changeTurn();
  std::cout<<getCurrentPlayer().getName()<< " destroyed ";
  changeTurn();
  std::cout<<getCurrentPlayer().getName()<< "'s "<<getCurrentPlayer().getPiece()<<"!"<<std::endl;
  changeTurn();
  std::cout<<std::endl;
  std::cout<<getCurrentPlayer().getName()<< " won the game!";
}

void connectNGame::connectN::print1() {
  std::cout<< getCurrentPlayer().getName() << "'s Firing Board"<<std::endl;
  boardFire1.display();
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<< getCurrentPlayer().getName() << "'s Placement Board"<<std::endl;
  boardPlace1.display();
}
void connectNGame::connectN::print2() {
  std::cout<< getCurrentPlayer().getName() << "'s Firing Board"<<std::endl;
  boardFire2.display();
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<< getCurrentPlayer().getName() << "'s Placement Board"<<std::endl;
  boardPlace2.display();
}

