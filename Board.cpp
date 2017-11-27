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

int Board::placePiece(Piece piece, int x, int y, int player){
  vector<vector<int>> squares = piece.getCoords();
  for(int i=0;i<squares.size();i++){
    vector<int> currsquare = squares[i];
    if(x+currpiece[0] >=20 || y+currpiece[1] >=20)
      return 1;
    boardmatrix[x+currpiece[0]][y+currpiece[1]] = player;
  }
  return 0;
}

void Board::print(){
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      cout << boardmatrix[i][j] << " ";
    }
    cout << endl;
  }
}
