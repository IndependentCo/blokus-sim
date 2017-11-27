//Board.cpp

#include <iostream>
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

void Board::print(){
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      cout << boardmatrix[i][j] << " ";
    }
    cout << endl;
  }
}

bool Board::isLegalMove(Piece piece, int x, int y, int player) {
    vector<vector<int>> squares = piece.getCoords();
    for(int i = 0, i < squares.size(); i++) {
        vector<int> currsquare = squares[i];
        // check adjacent
        if(boardmatrix[currsquare[0] - 1][currsquare[1]] == 0 && boardmatrix[currsquare[0] + 1][currsquare[1]]
           boardmatrix[currsquare[0]][currsquare[1] - 1] == 0 && boardmatrix[currsquare[0]][currsquare[1] + 1]) {
            adjacent = true;
        }
        if(boardmatrix[currsquare[0] - 1][currsquare[1] - 1] == player ||
           boardmatrix[currsquare[0] - 1][currsquare[1] + 1] == player ||
           boardmatrix[currsquare[0] + 1][currsquare[1] - 1] == player ||
           boardmatrix[currsquare[0] + 1][currsquare[1] + 1] == player) {
            diagonal = true;
        }
    }
    if(!adjacent && diagonal) {
        return true;
    } else {
        return false;
    }
}
