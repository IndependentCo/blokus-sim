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

using namespace std;

int main() {
  srand(time(NULL));
  Board board = Board();
  AI player1 = AI(1);
  AI player2 = AI(2);
  AI player3 = AI(3);
  AI player4 = AI(4);
  ofstream output;
  output.open("Output.txt");
  Move currmove;
  for(int j=0;j<1000;j++){
      board = Board();
      player1 = AI(1);
      player2 = AI(2);
      player3 = AI(3);
      player4 = AI(4);
    for(int i=0;i<21;i++){
      if(!player1.isDone()){
	currmove = player1.choose_random_move_from_vector(board, 1);
	board.placePiece(currmove.ReturnPiece(),currmove.ReturnX(),currmove.ReturnY());
      }
      if(!player2.isDone()){
	currmove = player2.choose_random_move_from_vector(board, 2);
	board.placePiece(currmove.ReturnPiece(),currmove.ReturnX(),currmove.ReturnY());
      }
      if(!player3.isDone()){
	currmove = player3.choose_random_move_from_vector(board, 3);
	board.placePiece(currmove.ReturnPiece(),currmove.ReturnX(),currmove.ReturnY());
      }
      if(!player4.isDone()){
	currmove = player4.choose_random_move_from_vector(board, 4);
	board.placePiece(currmove.ReturnPiece(),currmove.ReturnX(),currmove.ReturnY());
      }
    }
    board.print();
    board.printToText(output);
  }
  output.close();
  return 0;
}
