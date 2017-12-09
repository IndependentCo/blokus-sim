// Game Class

class Game
{
public:
  Game();
  void play(int strategy, int iterations, string outputfilename, string possmovesfilename);
  void reset();
private:
  Board board;
  AI player1 = AI(1);
  AI player2 = AI(2);
  AI player3 = AI(3);
  AI player4 = AI(4);
  ofstream output;
  ofstream possmoves;
};
    
