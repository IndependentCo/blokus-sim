#include <vector>
#include "Piece.hpp"
const int width = 20;
const int height = 20;
class Board
{
public:
  Board();
  int placePiece(Piece piece, int x, int y, int player);
  bool isLegalMove(Piece piece, int x, int y, int player);
  //void clearBoard();
  //int getScore(int player);
  //int getWinner();
  void print();
protected:
  int boardmatrix[width][height];
};
