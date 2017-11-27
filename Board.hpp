#include <vector>
#include "Piece.cpp"

class Board
{
public:
  Board();
  placePiece(Piece piece, int x, int y, int player);
  isLegalMove(Piece piece, int x, int y, int player);
  clearBoard();
  getScores();
  getWinner();
protected:
  int width = 20;
  int height = 20;
  int boardmatrix[width][height];
}
