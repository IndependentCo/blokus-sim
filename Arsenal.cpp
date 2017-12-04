// Arsenal.cpp

#include "Arsenal.hpp"
#include <iostream>

using namespace std;


Error_code sequential_search(const List<Move> &the_list,
                             const Move &target, int &position);

arsenal::arsenal() {
    moveList.clear();
}


arsenal::arsenal(const List<Move> &original) {
    moveList = original;
}


int arsenal::size() {
    return moveList.size();
}

Error_code arsenal::addMove(Move move) {
    return moveList.insert(0, move);
}


Move arsenal::getMoveAt(int position) {
    Move move;
    moveList.retrieve(position, move);
    return move;
}


Error_code arsenal::getMove(Move myMove, int &position) {
    return sequential_search(moveList, myMove, position);
}

Error_code arsenal::deleteMove(Move usedMove) {
    int position;
    Move move;
    if(getMove(usedMove, position) == success) {
    } else {
        return fail;
    }
    moveList.remove(position, move);
    return success;
}


void arsenal::clear() {
    moveList.clear();
}


bool arsenal::isDuplicate(Move myMove) {
    int s = moveList.size();
    for(int i = 0; i < s; i++) {
        Move thisMove;
        moveList.retrieve(i, thisMove);
        if(thisMove == myMove)
            return true;
    }
    return false;
}

Error_code sequential_search(const List<Move> &the_list,
              const Move &target, int &position)
/*
Post: If an entry in the_list has key equal to target, then return
success and the output parameter position locates such an entry
within the list.
Otherwise return not_present and position becomes invalid.
*/
{
  int s = the_list.size();
  for (position = 0; position < s; position++){
     Move temp_move;
     the_list.retrieve(position, temp_move);
     if (temp_move == target)return success;
  }
  return not_present;
} //sequential search
