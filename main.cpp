//
//  main.cpp
//  test_run_piece
//
//  Created by Alex Frasca on 11/19/17.
//  Copyright © 2017 Alex Frasca. All rights reserved.
//

#include <iostream>
#include "Move.cpp"
#include "Piece.cpp"
#include "Board.cpp"
#include "AI.cpp"

using namespace std;

int main() {
  Board board = Board();
  AI player1 = AI(1);
  AI player2 = AI(2);
  AI player3 = AI(3);
  AI player4 = AI(4);
  Move currmove;
  int count = 0;
  while(!player1.isDone() && !player2.isDone() && !player3.isDone() && !player4.isDone()){
    currmove = player1.choose_random_move_from_vector(board, 1);
    board.placePiece(currmove.ReturnPiece(),currmove.ReturnX(),currmove.ReturnY());
    currmove = player2.choose_random_move_from_vector(board, 2);
    board.placePiece(currmove.ReturnPiece(),currmove.ReturnX(),currmove.ReturnY());
    currmove = player3.choose_random_move_from_vector(board, 3);
    board.placePiece(currmove.ReturnPiece(),currmove.ReturnX(),currmove.ReturnY());
    currmove = player4.choose_random_move_from_vector(board, 4);
    board.placePiece(currmove.ReturnPiece(),currmove.ReturnX(),currmove.ReturnY());
    board.print();
    cout << endl;
    }
    return 0;
}
