// AI.cpp

#include "AI.hpp"
#include <vector>

AI::AI(int player) {
  initializeArsenal(player);
  done = false;
}

Move AI::choose_random_highest_move(Board board,int player){
  vector<Move> resultlist;
  vector<Move> resultlist1;
  vector<Move> resultlist2;
  vector<Move> resultlist3;
  vector<Move> resultlist4;
  vector<Move> resultlist5;
  vector<Piece> currpiece;
  Move move = Move();
  int priority;
  for(int i=0; i<arsenal.size(); i++){
    currpiece = arsenal[i];
    priority = currpiece[0].size();
    for(int x=0; x<20; x++){
      for(int y=0; y<20; y++){
	for(int possmove=0; possmove<currpiece.size();possmove++){
	  if(board.isLegalMove(currpiece[possmove],x,y) && priority==1){
	    move = Move(currpiece[possmove],x,y,priority);
	    resultlist1.push_back(move);
	  }
	  else if(board.isLegalMove(currpiece[possmove],x,y) && priority==2){
	    move = Move(currpiece[possmove],x,y,priority);
	    resultlist2.push_back(move);
	  }
	  else if(board.isLegalMove(currpiece[possmove],x,y) && priority==3){
	    move = Move(currpiece[possmove],x,y,priority);
	    resultlist3.push_back(move);
	  }
	  else if(board.isLegalMove(currpiece[possmove],x,y) && priority==4){
	    move = Move(currpiece[possmove],x,y,priority);
	    resultlist4.push_back(move);
	  }
	  else if(board.isLegalMove(currpiece[possmove],x,y) && priority==5){
	    move = Move(currpiece[possmove],x,y,priority);
	    resultlist5.push_back(move);
	  }
	}	
      }
    }
  }
  if(resultlist5.size()>0)
    resultlist = resultlist5;
  else if(resultlist4.size()>0)
    resultlist = resultlist4;
  else if(resultlist3.size()>0)
    resultlist = resultlist3;
  else if(resultlist2.size()>0)
    resultlist = resultlist2;
  else
    resultlist = resultlist1;
	  

  int length = resultlist.size(); 
  cout << player << " : " << length << endl;
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
    for(int i=0;i<arsenal.size(); i++){
        if(arsenal[i][1].getType() == type){
            arsenal.erase(arsenal.begin()+i); // removes the chosen piece from arsenal
        }
    }
    return resultlist[u];
}

Move AI::choose_random_move_from_vector(Board board, int player){
  //needs to comile a vector list of coordinates where moves are possible.
  //all possible moves should be included in the list.
  //list will be <x,y,piece>
  //Once the list is completed, uniformly choose a random move from the list.
  //return resulting <x,y,piece>
  vector<Move> resultlist;
  resultlist.clear();
  vector<Piece> currpiece;
  Move move = Move();
  int s = arsenal.size();
  int currpiecesize;
  for(int i=0; i<s; i++){
    currpiece = arsenal[i];
    currpiecesize = currpiece.size();
    for(int x=0; x<20; x++){
      for(int y=0; y<20; y++){
	for(int possmove=0; possmove<currpiecesize;possmove++){
	  if(board.isLegalMove(currpiece[possmove],x,y)){
	    move = Move(currpiece[possmove],x,y);
	    resultlist.push_back(move);
	  }
	}	
      }
    }
  }

  
  int length = resultlist.size();

  //for(int i=0;i < length;i++){
  //resultlist[i].ReturnPiece().print();
  //cout << endl;
  //}
  cout << player << " : " << length << endl;
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
    for(int i=0;i<arsenal.size(); i++){
        if(arsenal[i][1].getType() == type){
            arsenal.erase(arsenal.begin()+i); // removes the chosen piece from arsenal
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

void AI::reset(int player){
  Piece piece;
  arsenal.clear();
  initializeArsenal(player);
  done = false;
}

bool AI::isUnique(vector<Piece> prevpieces, Piece currpiece){
  for(int i=0;i<prevpieces.size();i++){
    if(currpiece.isEqual(prevpieces[i])){
      return false;
    }
  }
  return true;
}

void AI::initializeArsenal(int player){
  Piece piece;
  vector<Piece> currpieces;
  for(int i=0; i<21;i++){
    piece = Piece(i, player);
    for(int reflect=0; reflect<2; reflect++){
      for(int rotate=0; rotate<4; rotate++){
	if(isUnique(currpieces,piece)){
	  currpieces.push_back(piece);
	}
	piece.rotate(90);
      }
      piece.reflect(false);
    }
    arsenal.push_back(currpieces);
    currpieces.clear();
  }
}

void AI::test(){
  for(int i=0;i<arsenal.size();i++){
    for(int j=0;j<arsenal[i].size();j++){
      arsenal[i][j].print();
    }
    cout << "-------------------" << endl;
  }
}
