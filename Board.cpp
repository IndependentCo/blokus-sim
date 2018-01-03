//Board.cpp

#include <iostream>
#include <fstream>
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

void Board::clearBoard(){
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      boardmatrix[i][j] = 0;
    }
  }
}

int Board::placePiece(Piece piece, int x, int y){
  vector<vector<int> > squares = piece.getCoords();
  int player = piece.getPlayer();
  vector<int> currsquare;
  if(piece.getType() == -1)
    return 0;
  for(size_t i=0;i<squares.size();i++){
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

bool Board::isLegalMove(Piece piece, int x, int y) {
  bool diagonal = false;
  int player = piece.getPlayer();
  vector<vector<int> > squares = piece.getCoords();
  int s = squares.size();
  for(int i = 0; i < s; i++) {		//for each square of the piece
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
	if (isAdjacent(currx, curry, player))
		return false;
    //check diagonal
    if(isDiagonal(currx, curry, player))
      diagonal = true;
  }
  return diagonal;
}

bool Board::isAdjacent(int x, int y, int player) {
	bool flag = false;
	if (onBoard(x - 1, y)) {
		if (boardmatrix[x - 1][y] == player)
			flag = true;
	}
	if (onBoard(x + 1, y)) {
		if (boardmatrix[x + 1][y] == player)
			flag = true;
	}
	if (onBoard(x, y - 1)) {
		if (boardmatrix[x][y - 1] == player)
			flag = true;
	}
	if (onBoard(x, y + 1)) {
		if (boardmatrix[x][y + 1] == player)
			flag = true;
	}
	return flag;
}


bool Board::isDiagonal(int x,int y, int player){
	bool flag = false;
  if(x==0 && y==0 && player==1)//corner conditionals
    flag = true;
  else if(x==0 && y==19 && player==2)
    flag = true;
  else if(x==19 && y==19 && player==3)
    flag = true;
  else if(x==19 && y==0 && player==4)
    flag = true;   
  else {
	  if(onBoard(x-1,y-1)){
		  if (boardmatrix[x - 1][y - 1] == player)
			  flag = true;
	  }
	  if (onBoard(x + 1, y - 1)) {
		  if (boardmatrix[x + 1][y - 1] == player)
			  flag = true;
	  }
	  if (onBoard(x - 1, y + 1)) {
		  if (boardmatrix[x - 1][y + 1] == player)
			  flag = true;
	  }
	  if (onBoard(x + 1, y + 1)) {
		  if (boardmatrix[x + 1][y + 1] == player)
			  flag = true;
	  }
  }
  return flag;
}
    

bool Board::onBoard(int x, int y){
  if(x<0 || x>19 || y<0 || y>19)
    return false;
  return true;
}

void Board::printToText(ofstream &output){
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      output << boardmatrix[i][j];
    }
  }
  output<<","<<endl;
}
    


