// AI.cpp

#include "AI.hpp"

AI::AI() {
    for(int i = 0; i < 21; i++) {
        arsenal[i] = true;
    }
}

void AI::place_randomly(Board board, int player) {
    //check player's arsenal
    int choice = rand()%21;
    while(!arsenal[choice]) {
        int choice = rand()%21;
    }
    //get piece
    Piece curr_piece(choice + 1, player);
    //rotate and reflect randomly
    for(int i = 0; i<rand()%4; i++) {
        int random = rand()%6;
        curr_piece.rotate(90);
        if(random < 2) {
            curr_piece.reflect(true);
        } else if (random < 4) {
            curr_piece.reflect(false);
        }
    }
    //place it randomly
    while(true) {
        x = rand()%20;
        y = rand()%20;
        if(isLegalMove(curr_piece, x, y, player)) {
            placePiece(curr_piece, x, y, player);
            break;
        }
    }
}

void AI::place_biggest(Board board, int player) {
    int choice = 1;
    Piece curr_piece(choice, player);
    int max = curr_piece.size();
    //get max size
    for(int i = 2; i <= 21; i++) {
        if(arsenal[choice]) {
            Piece new_piece(i, player);
            if(new_piece.size() > max) {
                max = new_piece.size();
            }
        }
    }
    while(curr_piece.size() != max) {
        int choice = rand()%21;
        curr_piece = curr_piece(choice, player);
    }
    //place randomly
    while(true) {
        x = rand()%20;
        y = rand()%20;
        if(board.isLegalMove(curr_piece, x, y, player)) {
            board.placePiece(curr_piece, x, y, player);
            break;
        }
    }
}

void AI::aim_for_center(Board board, int player) {
    //check player's arsenal
    int choice = rand()%21;
    while(!arsenal[choice]) {
        int choice = rand()%21;
    }
    //get piece
    Piece curr_piece(choice + 1, player);
}
