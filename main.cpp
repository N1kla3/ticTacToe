#include <iostream>
#include "Game.h"

using namespace std;

int readFieldSize();
void readPoints(int *x, int *y);

int main()
{
    int n, x, y, k, checker;
    setlocale(LC_ALL, "Russian");

    while(true){
        n = readFieldSize();
        if(n == 0) return 0;
        Game *myGame = new Game(n);
        k = 1;

        while(true)
        {
            while(true)
            {
                myGame->showField();
                if(k == 1)cout << endl << "Õîä çà êðåñòèêè: ";
                else cout << endl << "Õîä çà íîëèêè: ";
                readPoints(&x, &y);
                if(myGame->checkPlace(x - 1, y - 1))
                {
                    myGame->setValue(x - 1, y - 1, k);
                    break;
                }
            }
            k = 3 - k;
            checker = myGame->checkWin();
            if(checker)myGame->showField();

            if(checker == 1)
                cout << "ÏÎÁÅÄÀ ÊÐÅÑÒÈÊÎÂ"<< endl;
            else if(checker == 2)
                cout << "ÏÎÁÅÄÀ ÍÎËÈÊÎÂ"<< endl;
            else if(checker == 3)
                cout << "ÍÈ×Üß"<< endl;
            if(checker)break;
        }
        delete myGame;
    }
}

int readFieldSize(){
    while(true){
        cout << "Âåäèòå ðàçìåð ïîëÿ : ";
        int n = 13;
        cin >> n;
        if(n > 0 && n < 10){
            return n;
        }else if(n > 10)
            return 0; //way to exit programm
        else cout << "\nÂâåäèòå êîððåêòíî\n";
        cin.clear();
        fflush(stdin);
    }
}

void readPoints(int *x, int *y){
        cin >> *x >> *y;
        if(*x == 0 || *y == 0){
            *x = -13; *y = -13;
            cout << "\nÂâåäèòå êîððåêòíî\n";
            cin.clear();
            fflush(stdin);
        }
}