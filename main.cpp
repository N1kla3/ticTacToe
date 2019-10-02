#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

int main()
{
    int n,x,y,i,k=1,j; Game G;
    setlocale(LC_ALL, "Russian");
    cout << "Âåäèòå ðàçìåð ïîëÿ N: ";
    cin >> n; G.MakeField(n);
    for(;;)
    {
        for(;;)
        {
            G.ShowField();
            if(k==1)cout << endl << "Õîä çà êðåñòèêè: ";
            else cout << endl << "Õîä çà íîëèêè: ";
            cin >> x >> y; if(G.CheckPlace(x-1,y-1))
            {
                G.SetValue(x-1,y-1,k); break;
            }
        }
        k=3-k; j=G.CheckWin(); if(j)G.ShowField();
        if(j==1)cout << "ÏÎÁÅÄÀ ÊÐÅÑÒÈÊÎÂ"<< endl; else
        if(j==2)cout << "ÏÎÁÅÄÀ ÍÎËÈÊÎÂ"<< endl; else
        if(j==3)cout << "ÍÈ×Üß"<< endl;
        if(j)return 0;
    }
    return 0;
}
