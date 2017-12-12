#ifndef Board_
#define Board_

using namespace std;
#include "Piece.hpp"
/* The classes below are exported */
#pragma GCC visibility push(default)
class Board
{
public:
  Board();
  int placePiece(Piece piece, int x, int y);
  bool isLegalMove(Piece piece, int x, int y);
  void clearBoard();
  //int getScore(int player);
  //int getWinner();
  void print();
  bool isDiagonal(int x, int y, int player);
  bool onBoard(int x, int y);
    void printToText(std::ofstream &output);
protected:
  int boardmatrix[20][20];
};


#pragma GCC visibility pop
#endif
