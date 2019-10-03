#include <iostream>
#include "Game.h"

using namespace std;

void Game::MakeField()
{   vector<int> fieldBuilder;
    K = fieldSize * fieldSize;
    for(I=0; I < fieldSize; I++)fieldBuilder.push_back(0);
    for(I=0; I < fieldSize; I++)field.push_back(fieldBuilder);
}

void Game::ShowField()
{
    for(I=0; I < fieldSize; I++)
    {
        for(J=0; J < fieldSize; J++)
        {
            if(J)cout << char(124);
            if(field[I][J] == 0)cout << " "; else
            if(field[I][J] == 1)cout << "X"; else cout << "O";
        }
        cout << endl;
        if(I < fieldSize - 1)for(J=0; J < fieldSize; J++)
        {
            if(J)cout << char(134); cout << char(173);
        }
        cout << endl;
    }
}

int Game::CheckWin()
{
    for(I=0; I < fieldSize; I++)
    {
        Sx=0; So=0; for(J=0; J < fieldSize; J++)
        {
            if(field[I][J] == 1)Sx++; else
            if(field[I][J] == 2)So++;
        }
        if(Sx == fieldSize)return 1; else if(So == fieldSize)return 2;
    }
    for(I=0; I < fieldSize; I++)
    {
        Sx=0; So=0; for(J=0; J < fieldSize; J++)
        {
            if(field[J][I] == 1)Sx++; else
            if(field[J][I] == 2)So++;
        }
        if(Sx == fieldSize)return 1; else if(So == fieldSize)return 2;
    }
    Sx=0; So=0;
    for(I=0; I < fieldSize; I++)
    {
        if(field[I][I] == 1)Sx++; else
        if(field[I][I] == 2)So++;
    }
    if(Sx == fieldSize)return 1; else if(So == fieldSize)return 2;
    Sx=0; So=0; for(I=0; I < fieldSize; I++)
    {
        if(field[I][fieldSize - I] == 1)Sx++; else
        if(field[I][fieldSize - I] == 2)So++;
    }
    if(Sx == fieldSize)return 1; else if(So == fieldSize)return 2;
    if(!K)return 3; else return 0;
}

int Game::GetValue(int ii, int jj)
{
    return field[ii][jj];
}

bool Game::CheckPlace(int ii, int jj)
{
    if((ii<0) || (jj<0) || (ii >= fieldSize) || (jj >= fieldSize))return false;
    return !GetValue(ii,jj);
}

void Game::SetValue(int ii, int jj, int val)
{
    field[ii][jj] = val;
    K--;
}
