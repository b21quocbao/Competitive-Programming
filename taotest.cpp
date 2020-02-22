#include <bits/stdc++.h>
#include "FileWork.h"
#include "FileChecker.h"
#include "FileInit.h"

using namespace std;

int main()
{
    ios::sync_with_stdio (0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand (time (nullptr));
    ofstream to ("taotest.out");
    for (int i = 0; i < ntest; ++ i)
    {
        work();
        process();
        // if ((!checker && system("fc test.out test.ans")) || (checker && work1()))
        // {
        //     PrintSol (0);   
        //     return 0;
        // }
    }
    PrintSol(1);
    return 0;
}
