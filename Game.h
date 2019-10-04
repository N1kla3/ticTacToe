#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
using namespace std;

class Game
{
private:
    int fieldSize, maxMoves;
    int **field;

public:
    explicit Game(int fSize);
    ~Game();
    void showField();
    int checkWin();
    bool checkPlace(int row, int column);
    void setValue(int row, int column, int val);
    int* operator [] (int i);
};

#endif // GAME_H_INCLUDED
