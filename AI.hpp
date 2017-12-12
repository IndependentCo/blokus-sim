// AI.hpp

using namespace std;

class AI
{
public:
  AI(int player);
  void place_randomly(Board board, int player);
  void place_biggest(Board board, int player);
  Move aim_for_center(Board board, int player, ofstream &record);
  Move choose_random_highest_move(Board board, int player, ofstream &record);
  Move choose_random_move_from_vector(Board board, int player, ofstream &record);
  bool isDone();
  int returnArsenalSize();
  bool isDuplicateMove(vector<Move> previousmoves, Move currmove);
  vector<Move> cleanseDuplicates(vector<Move> moves);
  void reset(int player);
  bool isUnique(vector<Piece> prevpieces, Piece currpiece);
  void initializeArsenal(int player);
  void test();
protected:
  std::vector<std::vector<Piece> >  arsenal;
  bool done;
};
