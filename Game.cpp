#include <iostream>
#include "Game.h"

using namespace std;

void Game::makeField()
{
    vector<int> fieldBuilder(fieldSize, 0);
    for(int i = 0; i < fieldSize; i++)field.push_back(fieldBuilder);
}

void Game::showField()
{
    cout << endl;
    for(int i = 0; i < fieldSize; i++)
    {
        for(int j = 0; j < fieldSize; j++)
        {
            if(j)cout << char(124);
            if(field[i][j] == 0)cout << " "; else
            if(field[i][j] == 1)cout << "X"; else cout << "O";
        }
        cout << endl;
        if(i < fieldSize - 1)
            for(int j = 0; j < fieldSize; j++){
                if(j)cout << char(134); cout << char(173);
        }
        cout << endl;
    }
}

int Game::checkWin()
{
    int i;
    int j;
    int maxSizeO;
    int maxSizeX;
    for(i = 0; i < fieldSize; i++)
    {
        maxSizeX = 0; maxSizeO = 0;
        for(j = 0; j < fieldSize; j++)
        {
            if(field[i][j] == 1)maxSizeX++; else
            if(field[i][j] == 2)maxSizeO++;
        }
        if(maxSizeX == fieldSize)return 1; else if(maxSizeO == fieldSize)return 2;
    }
    for(i = 0; i < fieldSize; i++)
    {
        maxSizeX = 0; maxSizeO = 0;
        for(j = 0; j < fieldSize; j++)
        {
            if(field[j][i] == 1)maxSizeX++; else
            if(field[j][i] == 2)maxSizeO++;
        }
        if(maxSizeX == fieldSize)return 1; else if(maxSizeO == fieldSize)return 2;
    }
    maxSizeX=0; maxSizeO=0;
    for(i = 0; i < fieldSize; i++)
    {
        if(field[i][i] == 1)maxSizeX++; else
        if(field[i][i] == 2)maxSizeO++;
    }
    if(maxSizeX == fieldSize)return 1;
    else if(maxSizeO == fieldSize)return 2;

    maxSizeX=0; maxSizeO=0;
    for(i = 0; i < fieldSize; i++)
    {
        if(field[i][fieldSize - i] == 1)
            maxSizeX++;
        else if(field[i][fieldSize - i] == 2)
            maxSizeO++;
    }
    if(maxSizeX == fieldSize)return 1;
    else if(maxSizeO == fieldSize)return 2;

    if(!k)return 3;
    else return 0;
}

int Game::getValue(int row, int column)
{
    return field[row][column];
}

bool Game::checkPlace(int row, int column)
{
    if((row < 0) || (column < 0) || (row >= fieldSize) || (column >= fieldSize))return false;
    return !getValue(row, column);
}

void Game::setValue(int row, int column, int val)
{
    field[row][column] = val;
    k--;
}
