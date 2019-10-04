#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    int n,x,y,k=1,checker;
    setlocale(LC_ALL, "Russian");
    cout << "������ ������ ���� : ";
    cin >> n;
    Game myGame(n);
    myGame.makeField();

    while(true)
    {
        while(true)
        {
            myGame.showField();
            if(k == 1)cout << endl << "��� �� ��������: ";
            else cout << endl << "��� �� ������: ";
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
            cout << "������ ���������"<< endl;
        else if(checker == 2)
            cout << "������ �������"<< endl;
        else if(checker == 3)
            cout << "�����"<< endl;
        if(checker)return 0;
    }
}
