// AI.cpp

#include "AI.hpp"
#include "Arsenal.cpp"
#include <vector>

AI::AI(int player) {
  Piece piece;
    for(int i = 0; i < 21; i++) {
      piece = Piece(i,player);
      arsenal.push_back(piece);
    }
    done = false;
}

Move AI::choose_random_move_from_vector(Board board, int player){
    //needs to comile a vector list of coordinates where moves are possible.
    //all possible moves should be included in the list.
    //list will be <x,y,piece>
    //Once the list is completed, uniformly choose a random move from the list.
    //return resulting <x,y,piece>
    arsenal resultlist;
    resultlist.clear();
    srand(time(NULL));
    Piece currpiece;
    Move move = Move();
    for(int i=0; i<arsenal.size(); i++){
        currpiece = arsenal.getMoveAt(i);
        for(int x=0; x<20; x++){
            for(int y=0; y<20; y++){
                for(int rotate=0; rotate<4; rotate++){
                    if(board.isLegalMove(currpiece,x,y)){
                        move = Move(currpiece,x,y);
                        if(!isDuplicateMove(resultlist, move)){
                            resultlist.addMove(move);
                        }
                    }
                    currpiece.rotate(90);
                }
            }
        }
    }
  
    int length = resultlist.size();
    if(length < 1)
        done = true; //no moves left
    int u = rand() % length;
    Piece result = resultlist.getMoveAt(u).ReturnPiece();
    int type = result.getType();
    // must adjust this following line for arsenal class
    arsenal.erase(arsenal.begin()+type); // removes the chosen piece from arsenal
    if(arsenal.size() == 0){
        done = true;
    }
    return resultlist.getMoveAt(u);
}

bool AI::isDuplicateMove(arsenal previousmoves, Move currmove){
    return previousmoves.isDuplicate(currmove);
}

bool AI::isDone(){
  return done;
}

int AI::returnArsenalSize(){
  return arsenal.size();
}
