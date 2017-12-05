// Game Implementation

#include "Game.hpp"

Game::Game() {
    board = Board();
}

void Game::play(int strategy, int iterations) {
    Move currmove;
    int count = 0;
    output.open("Output.txt");
    switch(strategy) {
    case 1:
        for(int j=0;j<iterations;j++){
	  while(!player1.isDone()||!player2.isDone()||!player3.isDone()||!player4.isDone()){
                if(!player1.isDone()){
                    currmove = player1.choose_random_move_from_vector(board, 1);
                    board.placePiece(currmove.ReturnPiece(),
                                     currmove.ReturnX(),
                                     currmove.ReturnY());
                }
                if(!player2.isDone()){
                    currmove = player2.choose_random_move_from_vector(board, 2);
                    board.placePiece(currmove.ReturnPiece(),
                                     currmove.ReturnX(),
                                     currmove.ReturnY());
                }
                if(!player3.isDone()){
                    currmove = player3.choose_random_move_from_vector(board, 3);
                    board.placePiece(currmove.ReturnPiece(),
                                     currmove.ReturnX(),
                                     currmove.ReturnY());
                }
                if(!player4.isDone()){
                    currmove = player4.choose_random_move_from_vector(board, 4);
                    board.placePiece(currmove.ReturnPiece(),
                                     currmove.ReturnX(),
                                     currmove.ReturnY());
                }
            }
            board.printToText(output);
	    reset();
        }
        output.close();
        break;
    case 2:
        break;
    }
}

void Game::reset() {
    board.clearBoard();
    player1.reset(1);
    player2.reset(2);
    player3.reset(3);
    player4.reset(4);
}
