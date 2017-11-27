#include <vector>
#include "Piece.cpp"

class Board
{
public:
  Board();
  int placePiece(Piece piece, int x, int y, int player);
  bool isLegalMove(Piece piece, int x, int y, int player);
  void clearBoard();
  int getScore(int player);
  int getWinner();
  void print();
protected:
  int width = 20;
  int height = 20;
  int boardmatrix[width][height];
}
