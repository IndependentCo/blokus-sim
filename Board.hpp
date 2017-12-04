#include <vector>
#include "Piece.hpp"
const int width = 20;
const int height = 20;
class Board
{
public:
  Board();
  int placePiece(Piece piece, int x, int y);
  bool isLegalMove(Piece piece, int x, int y);
  //void clearBoard();
  //int getScore(int player);
  //int getWinner();
  void print();
  bool isDiagonal(int x, int y, int player);
  bool onBoard(int x, int y);
  void printToText(ofstream &output);
protected:
  int boardmatrix[width][height];
};
