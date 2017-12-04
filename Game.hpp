// Game Class

class Game
{
public:
    Game();
    void play(int strategy, int iterations);
    void reset();
private:
    Board board;
    AI player1(int player);
    AI player2(int player);
    AI player3(int player);
    AI player4(int player);
    ofstream output;
};
    
