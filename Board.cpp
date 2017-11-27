//Board.cpp

#include <iostream>
#include "Piece.cpp"
#include <vector>
#include "Board.hpp"

using namespace std;

Board::Board(){
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      boardMatrix[i][j] = 0;
    }
  }
}
