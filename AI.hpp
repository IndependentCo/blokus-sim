// AI.hpp

using namespace std;

class AI
{
public:
  AI(int player);
  void place_randomly(Board board, int player);
  void place_biggest(Board board, int player);
  void aim_for_center(Board board, int player);
  Move choose_random_move_from_vector(Board board, int player);
  bool isDone();
  int returnArsenalSize();
  bool isDuplicateMove(vector<Move> previousmoves, Move currmove);
  vector<Move> cleanseDuplicates(vector<Move> moves);
  void reset(int player);
protected:
  std::vector<Piece>  arsenal;
  bool done;
};
