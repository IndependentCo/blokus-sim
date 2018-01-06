//Blokus Sim
//Created by Michael Hanlon and Alex Frasca, Oct 2017 - Jan 2018
//Very useful 

#include "Game.hpp"
#include <time.h>
#include <iostream>

int main() {
  srand((unsigned int)time(NULL));
  Game newgame = Game();
  newgame.playcustom(4,4,4,4,1000,"4444.txt", "4444PossMoves.txt");
  return 0;
}
