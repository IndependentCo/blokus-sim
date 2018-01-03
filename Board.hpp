
#ifndef Board_
#define Board_

#include <vector>
#include "Piece.hpp"
#include <fstream>
#include <iostream>

const int width = 20;
const int height = 20;
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
  bool isAdjacent(int x, int y, int player);
  bool isDiagonal(int x, int y, int player);
  bool onBoard(int x, int y);
  void printToText(std::ofstream &output);
protected:
  int boardmatrix[width][height];
};
#endif
