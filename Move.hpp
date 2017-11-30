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
protected:
  Piece piece;
  int x;
  int y;
};

bool operator == (const Move &move, const Move &move1);
  
