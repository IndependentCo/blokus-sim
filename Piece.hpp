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
  int coords[maxwidth][maxheight];
  int piecetype;
};
#endif
