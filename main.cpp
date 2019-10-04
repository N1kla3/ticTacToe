#include <iostream>
#include "Game.h"

using namespace std;

int readFieldSize();
void readPoints(int *x, int *y);

int main()
{
    int n, x, y, k=1, checker;
    setlocale(LC_ALL, "Russian");

    n = readFieldSize();
    if(n == 0) return 0;
    Game myGame(n);

    while(true)
    {
        while(true)
        {
            myGame.showField();
            if(k == 1)cout << endl << "��� �� ��������: ";
            else cout << endl << "��� �� ������: ";
            readPoints(&x, &y);
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

int readFieldSize(){
    while(true){
        cout << "������ ������ ���� : ";
        int n = 13;
        cin >> n;
        if(n > 0 && n < 10){
            return n;
        }else if(n > 10)
            return 0; //way to exit programm
        else cout << "\n������� ���������\n";
    }
}

void readPoints(int *x, int *y){
        cin >> *x >> *y;
        if(*x == 0 || *y == 0){
            *x = -13; *y = -13;
            cout << "\n������� ���������\n";
            cin.clear();
            fflush(stdin);
        }
}