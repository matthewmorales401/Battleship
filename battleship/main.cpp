#include <fstream>
#include <iostream>
#include "connectN.h"

int main(int argc, char** argv) {
  std::vector<std::string> configFile;
  std::ifstream inFile(argv[1]);
  
  if(argc==3){
    //std::cout<<"seed: " << std::stoi(argv[2])<<std::endl;
  }
  while(inFile.good()) {
    std::string line;
    inFile >> line;
    configFile.push_back(line);
  }
  int row = std::stoi(configFile.at(0));
  int column = std::stoi(configFile.at(1));
  std::map<std::string, int> ships;
  for (int i=3; i<configFile.size()-1; i=i+2) {
    ships[configFile.at(i)] = std::stoi(configFile.at(i+1));
  }
  
  /*for (const auto& each : ships) {
    const auto& key = each.first;
    const auto& val = each.second;
  }*/
  
  connectNGame::connectN game(row, column, ships);
  game.start();
  game.play();
  return 0;
}