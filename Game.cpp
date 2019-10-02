#include <iostream>
#include <vector>

using namespace std;

#include "game.h"

void Game::MakeField(int nn)
{
    em.clear(); F.clear(); N=nn; K=N*N;
    for(I=0; I<N; I++)em.push_back(0);
    for(I=0; I<N; I++)F.push_back(em);
}
void Game::ShowField()
{
    for(I=0; I<N; I++)
    {
        for(J=0; J<N; J++)
        {
            if(J)cout << char(124);
            if(F[I][J]==0)cout << " "; else
            if(F[I][J]==1)cout << "X"; else cout << "O";
        }
        cout << endl;
        if(I<N-1)for(J=0; J<N; J++)
        {
            if(J)cout << char(134); cout << char(173);
        }
        cout << endl;
    }
}
int Game::CheckWin()
{
    for(I=0; I<N; I++)
    {
        Sx=0; So=0; for(J=0; J<N; J++)
        {
            if(F[I][J]==1)Sx++; else
            if(F[I][J]==2)So++;
        }
        if(Sx==N)return 1; else if(So==N)return 2;
    }
    for(I=0; I<N; I++)
    {
        Sx=0; So=0; for(J=0; J<N; J++)
        {
            if(F[J][I]==1)Sx++; else
            if(F[J][I]==2)So++;
        }
        if(Sx==N)return 1; else if(So==N)return 2;
    }
    Sx=0; So=0; for(I=0; I<N; I++)
    {
        if(F[I][I]==1)Sx++; else
        if(F[I][I]==2)So++;
    }
    if(Sx==N)return 1; else if(So==N)return 2;
    Sx=0; So=0; for(I=0; I<N; I++)
    {
        if(F[I][N-I]==1)Sx++; else
        if(F[I][N-I]==2)So++;
    }
    if(Sx==N)return 1; else if(So==N)return 2;
    if(!K)return 3; else return 0;
}
int Game::GetValue(int ii, int jj)
{
    return F[ii][jj];
}
bool Game::CheckPlace(int ii, int jj)
{
    if((ii<0) || (jj<0) || (ii>=N) || (jj>=N))return 0;
    return !GetValue(ii,jj);
}
void Game::SetValue(int ii, int jj, int val)
{
    F[ii][jj]=val; K--; return;
}
