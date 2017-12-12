//Move.hpp
#ifndef Move_
#define Move_

#include "Piece.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
/* The classes below are exported */
#pragma GCC visibility push(default)
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


#pragma GCC visibility pop
#endif

  
