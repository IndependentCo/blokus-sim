// Game Implementation

#include "Game.hpp"

Game::Game() {
    board = Board();
}

void Game::playcustom(int strategy1, int strategy2, int strategy3, int strategy4, int iterations, string outputfilename, string possiblemovesfilename) {Move currmove;
  output.open(outputfilename);
  //new output file to hold the number of possible moves each player has
  //throughout the game
  possmoves.open(possmovesfilename); 
  for(int i=0;i<iterations;i++){
    reset();

      while(!player1.isDone()||!player2.isDone()||!player3.isDone()||!player4.isDone()){
	if(!player1.isDone() && strategy1==1){
	  currmove = player1.choose_random_move_from_vector(board, 1,possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player1.isDone() && strategy1==2){
	  currmove = player1.choose_random_highest_move(board, 1, possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player2.isDone() && strategy2==1){
	  currmove = player2.choose_random_move_from_vector(board, 2,possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player2.isDone() && strategy2==2){
	  currmove = player2.choose_random_highest_move(board, 2, possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player3.isDone() && strategy3==1){
	  currmove = player3.choose_random_move_from_vector(board, 3,possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	
	if(!player3.isDone() && strategy3==2){
	  currmove = player3.choose_random_highest_move(board, 3, possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player4.isDone() && strategy4==1){
	  currmove = player4.choose_random_move_from_vector(board, 4,possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player4.isDone() && strategy4==2){
	  currmove = player4.choose_random_highest_move(board, 4, possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	cout << endl;
      }
      board.print();
      board.printToText(output);
      possmoves << endl;
  }
  output.close();
  possmoves.close();
}

void Game::play(int strategy, int iterations, string outputfilename, string possmovesfilename) {
  Move currmove;
  int count = 0;
  output.open(outputfilename);
  //new output file to hold the number of possible moves each player has
  //throughout the game
  possmoves.open(possmovesfilename); 
  for(int i=0;i<iterations;i++){
    reset();
    switch(strategy) {
    case 1:
      while(!player1.isDone()||!player2.isDone()||!player3.isDone()||!player4.isDone()){
	if(!player1.isDone()){
	  currmove = player1.choose_random_move_from_vector(board, 1,possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player2.isDone()){
	  currmove = player2.choose_random_move_from_vector(board, 2,possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player3.isDone()){
	  currmove = player3.choose_random_move_from_vector(board, 3,possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player4.isDone()){
	  currmove = player4.choose_random_move_from_vector(board, 4,possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	cout << endl;
      }
      board.print();       
      break;
    case 2:
      while(!player1.isDone()||!player2.isDone()||!player3.isDone()||!player4.isDone()){
	board.print();
	if(!player1.isDone()){
	  currmove = player1.choose_random_highest_move(board, 1, possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player2.isDone()){
	  currmove = player2.choose_random_highest_move(board, 2, possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player3.isDone()){
	  currmove = player3.choose_random_highest_move(board, 3, possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	if(!player4.isDone()){
	  currmove = player4.choose_random_highest_move(board, 4, possmoves);
	  board.placePiece(currmove.ReturnPiece(),
			   currmove.ReturnX(),
			   currmove.ReturnY());
	}
	cout << endl;
      }	  
      break;
    }
    board.printToText(output);
    possmoves << endl;
  }
  output.close();
  possmoves.close();
}

void Game::reset() {
  board.clearBoard();
  player1.reset(1);
  player2.reset(2);
  player3.reset(3);
  player4.reset(4);
}
