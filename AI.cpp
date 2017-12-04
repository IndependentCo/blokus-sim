// AI.cpp

#include "AI.hpp"
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
    vector<Move> resultlist;
    resultlist.clear();
    Piece currpiece;
    Move move = Move();
    int s = arsenal.size();
    for(int i=0; i<s; i++){
        currpiece = arsenal[i];
        for(int x=0; x<20; x++){
            for(int y=0; y<20; y++){
                for(int rotate=0; rotate<4; rotate++){
                    if(board.isLegalMove(currpiece,x,y)){
                        move = Move(currpiece,x,y);
                        //if(!isDuplicateMove(resultlist,move)){
                        resultlist.push_back(move);
                        //}
                    }
                    currpiece.rotate(90);
                }
            }
        }
    }
  
    int length = resultlist.size();
    if(length==0){
        done = true; //no moves left
        return Move(); //returns a blank move to avoid error
    }
    if(arsenal.size() == 0){
        done = true;
    }
    int u = rand() % length;
    Piece result = resultlist[u].ReturnPiece();
    int type = result.getType();
    int t = arsenal.size();
    for(int i=0;i<t; i++){
        if(arsenal[i].getType() == type){
            arsenal.erase(arsenal.begin()+i); // removes the chosen piece from arsenal
            t--;
        }
    }
    return resultlist[u];
}

bool AI::isDuplicateMove(vector<Move> previousmoves, Move currmove){
    for(size_t i=0;i<previousmoves.size();i++){
        if(currmove.isEqual(previousmoves[i]))
            return true;
    }
    return false;
}

bool AI::isDone(){
    return done;
}

int AI::returnArsenalSize(){
    return arsenal.size();
}
