// Game Implementation

#include "Game.hpp"

Game::Game() {
    board = Board();
    player1 = AI(1);
    player2 = AI(2);
    player3 = AI(3);
    player4 = AI(4);
}

void Game::play(int strategy, int iterations) {
    Move currmove;
    int count = 0;
    output.open("Output.txt");
    switch(strategy) {
    case 1:
        for(int j=0;j<iterations;j++){
            for(int i=0;i<21;i++){
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
        }
        output.close();
        break;
    case 2:
        break;
    }
}

void Game::reset() {
    board.clearBoard();
}
