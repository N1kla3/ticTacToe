#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
using namespace std;

class Game
{
    private:
      int N,I,J,K,Sx,So; vector<int> em;
      vector< vector<int> > F;

    public:
      void MakeField(int nn);
      void ShowField();
      int CheckWin();
      int GetValue(int ii, int jj);
      bool CheckPlace(int ii, int jj);
      void SetValue(int ii, int jj, int val);
};

#endif // GAME_H_INCLUDED
