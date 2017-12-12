// Game Class
#ifndef Game_
#define Game_

#include "Board.hpp"
#include "AI.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
/* The classes below are exported */
#pragma GCC visibility push(default)
class Game
{
public:
  Game();
  void play(int strategy, int iterations, string outputfilename, string possmovesfilename);
  void playcustom(int strategy1, int strategy2, int strategy3, int strategy4, int iterations, string outputfilename, string possmovesfilename);
  void reset();
private:
  Board board;
  AI player1;
  AI player2;
  AI player3;
  AI player4;
  ofstream output;
  ofstream possmoves;
};
    
#pragma GCC visibility pop
#endif
