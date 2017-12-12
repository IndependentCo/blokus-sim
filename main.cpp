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
#include <vector>
using namespace std;
#include "Piece.cpp"
#include "Move.cpp"
#include "Board.cpp"
#include "AI.cpp"
#include "Game.cpp"

int main() {
  srand(time(NULL));
  Game newgame = Game();
  //newgame.playcustom(1,1,1,1,500,"1111.txt", "1111_PossMoves.txt");
  //newgame.playcustom(2,1,1,1,500,"2111.txt", "2111_PossMoves.txt");
  //newgame.playcustom(3,1,1,1,500,"3111.txt", "3111_PossMoves.txt");
  //newgame.playcustom(2,2,2,2,500,"2222.txt", "2222_PossMoves.txt");
  //newgame.playcustom(3,2,2,2,500,"3222.txt", "3222_PossMoves.txt");
  //newgame.playcustom(1,3,1,2,500,"1312.txt", "1312_PossMoves.txt");
  //newgame.playcustom(1,1,1,2,500,"1112.txt", "1112_PossMoves.txt");
  //newgame.playcustom(1,1,1,3,500,"1113.txt", "1113_PossMoves.txt");
  //newgame.playcustom(3,3,3,3,500,"3333.txt", "3333_PossMoves.txt");
  newgame.play(1,5,"test1.txt","test2.txt");
  
  return 0;
}
