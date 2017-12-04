#include "Move.hpp"

Move::Move(){
  piece = Piece();
  x = -1;
  y = -1;
}

Move::Move(Piece piece1, int x1, int y1){
  piece = piece1;
  x = x1;
  y = y1;
}

Piece Move::ReturnPiece(){
  return(piece);
}

int Move::ReturnX(){
  return(x);
}
int Move::ReturnY(){
  return(y);
}
std::vector<int> Move::ReturnXY(){
  std::vector<int> xy;
  xy.push_back(x);
  xy.push_back(y);
  return(xy);
}

bool Move::isEqual(Move move){
  if(piece.isEqual(move.ReturnPiece()) && move.ReturnX() == x && move.ReturnY()==y)
    return true;
  else
    return false;
}
