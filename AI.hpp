// AI.hpp
#ifndef AI_
#define AI_

#include "Board.hpp"
#include <vector>
#include "Move.hpp"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
class AI
{
public:
  AI(int player);
  Move aim_for_center(Board board, int player, ofstream &record);
  Move aim_for_corner(Board board, int player, ofstream &record);
  Move choose_random_highest_move(Board board, int player, ofstream &record);
  Move choose_random_move_from_vector(Board board, int player, ofstream &record);
  bool isDone();
  int returnArsenalSize();
  bool isDuplicateMove(vector<Move> previousmoves, Move currmove);
  vector<Move> cleanseDuplicates(vector<Move> moves);
  void reset(int player);
  bool isUnique(vector<Piece> prevpieces, Piece currpiece);
  void initializeArsenal(int player);
  void test();
protected:
  std::vector<std::vector<Piece> >  arsenal;
  bool done;
};
#endif
