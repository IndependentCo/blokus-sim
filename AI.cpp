// AI.cpp

#include "AI.hpp"

AI::AI(int player) {
    for(int i = 0; i < 21; i++) {
      arsenal[i] = Piece(i,player);
    }
}

Move AI::choose_random_move_from_vector(Board board, int player){
  //needs to comile a vector list of coordinates where moves are possible.
  //all possible moves should be included in the list.
  //list will be <x,y,piece>
  //Once the list is completed, uniformly choose a random move from the list.
  //return resulting <x,y,piece>
  vector<Move> resultlist;
  Piece currpiece;
  Move move = Move();
  for(int i=0; i<21; i++){
    currpiece = arsenal[i];
    for(int x=0; x<20; x++){
      for(int y=0; y<20; y++){
	for(int rotate=0; rotate<4; rotate++){
	  currpiece.rotate(90);
	  if(board.isLegalMove(currpiece,x,y)){
	    move = Move(currpiece,x,y);
	    resultlist.push_back(move);
	  }
	}
      }
    }
  }

int length = resultlist.size();
int u = rand() % length;
return resultlist[u];
}
