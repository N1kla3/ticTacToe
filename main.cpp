#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    int n,x,y,i,k=1,j;
    setlocale(LC_ALL, "Russian");
    cout << "Âåäèòå ðàçìåð ïîëÿ fieldSize: ";
    cin >> n;
    Game myGame(n);
    myGame.MakeField();

    while(true)
    {
        while(true)
        {
            myGame.ShowField();
            if(k==1)cout << endl << "Õîä çà êðåñòèêè: ";
            else cout << endl << "Õîä çà íîëèêè: ";
            cin >> x >> y; if(myGame.CheckPlace(x - 1, y - 1))
            {
                myGame.SetValue(x - 1, y - 1, k); break;
            }
        }
        k = 3 - k;
        j = myGame.CheckWin();
        if(j)myGame.ShowField();

        if(j==1)
            cout << "ÏÎÁÅÄÀ ÊÐÅÑÒÈÊÎÂ"<< endl;
        else if(j==2)
            cout << "ÏÎÁÅÄÀ ÍÎËÈÊÎÂ"<< endl;
        else if(j==3)
            cout << "ÍÈ×Üß"<< endl;
        if(j)return 0;
    }
}
