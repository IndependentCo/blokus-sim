#include "listL.cc"
#include "Move.cpp"

class arsenal
{
public:
    arsenal();
    arsenal(const List<Move> &original);
    int size();
    Error_code addMove(Move move);
    Move getMoveAt(int position);
    Error_code getMove(Move myMove, int &position);
    Error_code deleteMove(Move usedMove);
    void clear();
protected:
    bool isDuplicate(Move myMove);
    List<Move> moveList; 
};