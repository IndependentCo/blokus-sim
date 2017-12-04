//Move.hpp
#include "Piece.hpp"
class Move
{
public:
  Move();
  Move(Piece piece, int x, int y);
  Piece ReturnPiece();
  int ReturnX();
  int ReturnY();
  std::vector<int> ReturnXY();
  bool isEqual(Move move);
protected:
  Piece piece;
  int x;
  int y;
};

  
