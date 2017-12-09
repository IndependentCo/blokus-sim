//
//  main.cpp
//  test_run_piece
//
//  Created by Alex Frasca on 11/19/17.
//  Copyright © 2017 Alex Frasca. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Move.cpp"
#include "Piece.cpp"
#include "Board.cpp"
#include "AI.cpp"
#include "Game.cpp"

using namespace std;

int main() {
  srand(time(NULL));
  Game newgame = Game();
  //newgame.playcustom(2,1,1,1,10,"P1Strat2.txt", "P1Strat2PossMoves.txt");
  newgame.play(2,5,"test1.txt","test2.txt");
  return 0;
}
