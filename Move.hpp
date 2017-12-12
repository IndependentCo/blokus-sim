//Move.hpp
#include "Piece.hpp"
class Move
{
public:
  Move();
  Move(Piece piece, int x, int y);
  Move(Piece piece, int x, int y, int priority1);
  Piece ReturnPiece();
  int ReturnX();
  int ReturnY();
  std::vector<int> ReturnXY();
  bool isEqual(Move move);
    int priority;
protected:
  Piece piece;
  int x;
  int y;
};

  
