// AI.h

#include "Piece.hpp"
#include "Board.hpp"

class AI
{
 public:
    AI();
    void place_randomly(Board board, int player);
    void place_biggest(Board board, int player);
    void aim_for_center(Board board, int player);
 protected:
    bool arsenal[21];
};
