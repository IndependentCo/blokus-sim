//Board.cpp

#include <iostream>
#include <vector>
#include "Board.hpp"

using namespace std;

Board::Board(){
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      boardmatrix[i][j] = 0;
    }
  }
}

int Board::placePiece(Piece piece, int x, int y, int player){
  vector<vector<int>> squares = piece.getCoords();
  vector<int> currsquare;
  for(int i=0;i<squares.size();i++){
    currsquare = squares[i];
    if((x+currsquare[0]) >=20 || (y+currsquare[1]) >=20)
      return 1;
    boardmatrix[(x+currsquare[0])][(y+currsquare[1])] = player;
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

bool Board::isLegalMove(Piece piece, int x, int y, int player) {
  bool diagonal = false;
  vector<vector<int>> squares = piece.getCoords();
  for(int i = 0; i < squares.size(); i++) {
        vector<int> currsquare = squares[i];
	int currx = x + currsquare[0];
	int curry = y + currsquare[1];
	//check in bounds
	if(currx >=20 || currx <0)
	  return false;
	if(curry >=20 || curry <0)
	  return false;
	//check if square is empty
	if(boardmatrix[currx][curry]!=0)
	  return false;
        // check adjacent
        if(boardmatrix[currx - 1][curry] != player && boardmatrix[currx + 1][curry] != player && 
           boardmatrix[currx][curry - 1] != player && boardmatrix[currx][curry + 1] != player) {
	  return false;
        }
        if(boardmatrix[currx - 1][curry - 1] == player ||
           boardmatrix[currx - 1][curry + 1] == player ||
           boardmatrix[currx + 1][curry - 1] == player ||
           boardmatrix[currx + 1][curry + 1] == player) {
            diagonal = true;
        }
    }
  return diagonal;
}


