#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
using namespace std;

class Game
{
private:
    int fieldSize,k;
    vector<vector<int>> field;

public:
    explicit Game(int fSize) : fieldSize(fSize){
        k = fieldSize * fieldSize;
    }
    ~Game(){
        cout << "Game over!";
    }
    void makeField();
    void showField();
    int checkWin();
    int getValue(int row, int column);
    bool checkPlace(int row, int column);
    void setValue(int row, int column, int val);
};

#endif // GAME_H_INCLUDED
