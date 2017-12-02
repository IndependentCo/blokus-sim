#include "listL.cc"
#include "Move.cc"

class arsenal
{
public:
    arsenal();
    Move getMoveAt(int position);
    Move getMove(Move myMove);
    void deleteMoveAt(int position);
    void deleteMove(Move usedMove);
    void clear();
    void print();
protected:
    void isDuplicate(Move myMove);
    List<Move> arsenal; 
};
