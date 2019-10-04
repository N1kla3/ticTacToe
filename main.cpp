#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    int n,x,y,k=1,checker;
    setlocale(LC_ALL, "Russian");
    cout << "Âåäèòå ðàçìåð ïîëÿ : ";
    cin >> n;
    Game myGame(n);
    myGame.makeField();

    while(true)
    {
        while(true)
        {
            myGame.showField();
            if(k == 1)cout << endl << "Õîä çà êðåñòèêè: ";
            else cout << endl << "Õîä çà íîëèêè: ";
            cin >> x >> y;
            if(myGame.checkPlace(x - 1, y - 1))
            {
                myGame.setValue(x - 1, y - 1, k);
                break;
            }
        }
        k = 3 - k;
        checker = myGame.checkWin();
        if(checker)myGame.showField();

        if(checker == 1)
            cout << "ÏÎÁÅÄÀ ÊÐÅÑÒÈÊÎÂ"<< endl;
        else if(checker == 2)
            cout << "ÏÎÁÅÄÀ ÍÎËÈÊÎÂ"<< endl;
        else if(checker == 3)
            cout << "ÍÈ×Üß"<< endl;
        if(checker)return 0;
    }
}
