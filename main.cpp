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
  Game newgame;
  newgame.play(1, 1);
  return 0;
}
