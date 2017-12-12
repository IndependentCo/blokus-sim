/****************************************************************************************************************
 //  Piece.hpp (Specification File)
 //
 //  Contents: Gives the specification for the piece object.
 //  Author: Alex Frasca
 //  Written: 11/19/17
 ****************************************************************************************************************/

#ifndef Piece_
#define Piece_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
/* The classes below are exported */
#pragma GCC visibility push(default)

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
  std::vector<std::vector<int> > getCoords();
  int getType();
  bool isEqual(Piece piece);
    bool hasSingleSymmetry();
    bool hasDoubleSymmetry();
    bool hasQuadSymmetry();
protected:
  void rotate_180();
  int player;
  int height;
  int width;
  int coords[5][5];
  int piecetype;
};


#pragma GCC visibility pop
#endif
