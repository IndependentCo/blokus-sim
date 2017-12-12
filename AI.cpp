// AI.cpp

#include "AI.hpp"

AI::AI() {
    arsenal.clear();
    done = false;
}

AI::AI(int player) {
    initializeArsenal(player);
    done = false;
}

Move AI::choose_random_highest_move(Board board,int player,ofstream &record){
    vector<Move> resultlist;
    vector<Piece> currpiece;
    Move move;
    int s = arsenal.size();
    int currsize;
    cout << player << " : " << s << endl;
    //create the vector of all possible unique moves
    for(int i=0; i<s; i++){
        currpiece = arsenal[i];
        currsize = currpiece.size();
        for(int x=0; x<20; x++){
            for(int y=0; y<20; y++){
                for(int possmove=0; possmove<currsize;possmove++){
                    if(board.isLegalMove(currpiece[possmove],x,y)){
                        move = Move(currpiece[possmove],x,y);
                        resultlist.push_back(move);
                    } 
                }	
            }
        }
    }
    int length = resultlist.size();
    if(arsenal.size()==21 && player==4 && length!=58){
        for(int i=0;i < length;i++){
            resultlist[i].ReturnPiece().print();
            cout << endl;
        }
    }
    cout << player << " : " << length << endl;
    if(length==0){
        done = true; //no moves left
        return Move(); //returns a blank move to avoid error
    }

    Move biggest = resultlist[0];
    //find the biggest piece
    for(int i = 1; i < length; i++) {
        if(biggest.ReturnPiece().size() > resultlist[i].ReturnPiece().size())
            biggest = resultlist[i];
    }
    //make the list consist of only the biggest pieces
    for(int i=0;i<length;i++){
        if(resultlist[i].ReturnPiece().size()<biggest.ReturnPiece().size()){
            resultlist.erase(resultlist.begin() + i);
            i--;
        }
						 
    }
    
    length = resultlist.size();
    int u = rand() % length;
    Piece result = resultlist[u].ReturnPiece();
    int type = result.getType();

    for(size_t i=0;i<arsenal.size(); i++){
        if(arsenal[i][0].getType() == type){
            arsenal.erase(arsenal.begin()+i); // removes the chosen piece from arsenal
        }
    }
    if(arsenal.size() == 0){
        done = true;
    }
    return resultlist[u];
}

Move AI::choose_random_move_from_vector(Board board, int player, ofstream &record){
    vector<Move> resultlist;
    vector<Piece> currpiece;
    Move move;
    int s = arsenal.size();
    int currsize;
    cout << player << " : " << s << endl;
    //create the vector of all possible unique moves
    for(int i=0; i<s; i++){
        currpiece = arsenal[i];
        currsize = currpiece.size();
        if(s==21 && player==1){
            cout << endl;
            cout << currsize << endl;
        }
        for(int x=0; x<20; x++){
            for(int y=0; y<20; y++){
                for(int possmove=0; possmove<currsize;possmove++){
                    if(board.isLegalMove(currpiece[possmove],x,y)){
                        move = Move(currpiece[possmove],x,y);
                        resultlist.push_back(move);
                    }
                        if(s==21 && player==1){
                        cout << x << "," << y << endl;
                        cout << possmove <<endl;
                        }
                }	
            }
        }
       
    }
    int length = resultlist.size();
    cout << player << " : " << arsenal.size() << endl;
    if(arsenal.size()==21 && length!=58){
        for(int i=0;i < length;i++){
            resultlist[i].ReturnPiece().print();
            cout << endl;
        }
    }

    record << player << ":" << length << ",";
    cout << player << " : " << length << endl;

    if(length==0){
        done = true; //no moves left
        return Move(); //returns a blank move to avoid error
    }
    int u = rand() % length;
    Piece result = resultlist[u].ReturnPiece();
    int type = result.getType();
    for(size_t i=0;i<arsenal.size(); i++){
        if(arsenal[i][0].getType() == type){
            arsenal.erase(arsenal.begin()+i); // removes the chosen piece from arsenal
        }
	
    }
    //cout << player << " size: " << arsenal.size()<< endl;
    if(arsenal.size() == 0){
        done = true;
    }
    return resultlist[u];
}

Move AI::aim_for_center(Board board, int player, ofstream &record) {
    vector<Move> resultlist;
    resultlist.clear();
    vector<Piece> currpiece;
    currpiece.clear();
    Move move = Move();
    int s = arsenal.size();
    int currsize;
    //create the vector of all possible unique moves
    for(int i=0; i<s; i++){
        currpiece = arsenal[i];
        currsize = currpiece.size();
        for(int x=0; x<20; x++){
            for(int y=0; y<20; y++){
                for(int possmove=0; possmove<currsize;possmove++){
                    if(board.isLegalMove(currpiece[possmove],x,y)){
                        move = Move(currpiece[possmove],x,y);
                        resultlist.push_back(move);
                    } 
                }	
            }
        }
    }
    
    cout << player << " : " << s << endl;
    int length = resultlist.size();
    if(arsenal.size()==21 && length!=58){
        for(int i=0;i < length;i++){
            resultlist[i].ReturnPiece().print();
            cout << endl;
        }
    }
    record << player << ":" << length << ",";
    cout << player << " : " << length << endl;
    if(length==0){
        done = true; //no moves left
        return Move(); //returns a blank move to avoid error
    }

    Move biggest = resultlist[0];
    //find the biggest piece
    for(int i = 1; i < length; i++) {
        if(biggest.ReturnPiece().size() > resultlist[i].ReturnPiece().size())
            biggest = resultlist[i];
    }
    //make the list consist of only the biggest pieces
    for(int i=0;i<length;i++){
        if(resultlist[i].ReturnPiece().size()<biggest.ReturnPiece().size()){
            resultlist.erase(resultlist.begin() + i);
            i--;
        }			 
    }

    
  
    length = resultlist.size();
    for(int i = 0; i < length; i++) {
        resultlist[i].priority = (resultlist[i].ReturnX() * resultlist[i].ReturnY());
    }
    int my_priority = resultlist[0].priority;
    //find highest priority
    for(int i = 1; i < length; i++) {
        if(resultlist[i].priority > my_priority)
            my_priority = resultlist[i].priority;
    }
    Piece result;
    int pos;
    //get move
    for(int i = 0; i < length; i++) {
        if(resultlist[i].priority == my_priority) {
            result = resultlist[i].ReturnPiece();
            pos = i;
        }
    }
    int type = result.getType();

    for(size_t i=0;i<arsenal.size(); i++){
        if(arsenal[i][0].getType() == type){
            arsenal.erase(arsenal.begin()+i); // removes the chosen piece from arsenal
        }
    }
    if(arsenal.size() == 0){
        done = true;
    }
    return resultlist[pos];
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
    arsenal.clear();
    initializeArsenal(player);
    done = false;
}

bool AI::isUnique(vector<Piece> prevpieces, Piece currpiece){
    for(size_t i=0;i<prevpieces.size();i++){
        if(currpiece.isEqual(prevpieces[i])){
            return false;
        }
    }
    return true;
}

void AI::initializeArsenal(int player){
    arsenal.clear();
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
            piece.reflect(true);
        }
    
        arsenal.push_back(currpieces);
        currpieces.clear();
    }
}

void AI::test(){
    for(size_t i=0;i<arsenal.size();i++){
        for(size_t j=0;j<arsenal[i].size();j++){
            arsenal[i][j].print();
        }
        cout << "-------------------" << endl;
    }
}
