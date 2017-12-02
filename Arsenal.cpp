// Arsenal.cpp

#include "Arsenal.hpp"
#include <iostream>

using namespace std;

Error_code sequential_search(const List<Record> &the_list,
                             const Key &target, int &position);

arsenal::arsenal() {
    arsenal.clear();
}


arsenal::arsenal(const List<Move> &original) {
    arsenal = original;
}


int arsenal::size() {
    return arsenal.size();
}

Error_code arsenal::addMove(Move move) {
    return arsenal.insert(0, move);
}


Move arsenal::getMoveAt(int position) {
    Move move;
    arsenal.retrieve(position, move);
    return move;
}


Error_code arsenal::getMove(Move myMove, int &position) {
    return sequential_search(arsenal, myMove, position);
}

void arsenal::deleteMove(Move usedMove) {
    Move move;
    sequential_search(arsenal, usedMove, position);
    arsenal.remove(position, move);
    delete move;
}


void arsenal::clear() {
    arsenal.clear();
}


bool arsenal::isDuplicate(Move myMove) {
    for(int i = 0; i < arsenal.size(); i++) {
        Move thisMove;
        arsenal.retrieve(i, thisMove);
        if(thisMove == myMove)
            return true;
    }
    return false;
}

Error_code sequential_search(const List<Record> &the_list,
              const Key &target, int &position)
/*
Post: If an entry in the_list has key equal to target, then return
success and the output parameter position locates such an entry
within the list.
Otherwise return not_present and position becomes invalid.
*/
{
  int s = the_list.size();
  for (position = 0; position < s; position++){
     Record data;
     the_list.retrieve(position, data);
     if ((Key)data == target)return success;
  }
  return not_present;
} //sequential search
