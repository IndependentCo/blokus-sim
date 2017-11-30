/****************************************************************************************************************
 //  Piece.hpp (Specification File)
 //
 //  Contents: Gives the specification for the piece object.
 //  Author: Alex Frasca
 //  Written: 11/19/17
 ****************************************************************************************************************/

#ifndef Piece_
#define Piece_
#include <vector>

/* The classes below are exported */
#pragma GCC visibility push(default)

const int maxwidth = 5;
const int maxheight = 5;

class Piece
{
public:
  Piece();
  void initialize(int piece_type);
  void print();
  void rotate(int degrees);
  void reflect(bool horiz);
  int getPlayer();
  int size();
  Piece(int piece_type, int player);
  std::vector<std::vector<int>> getCoords();
  int getType();
protected:
  void rotate_180();
  int player;
  int height;
  int width;
  int coords[maxwidth][maxheight];
  int piecetype;
};

#pragma GCC visibility pop
#endif
