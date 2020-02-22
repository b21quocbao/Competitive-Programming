#include <bits/stdc++.h>

using namespace std;

double ma, TimeS;
const int ntest = 1000;
bool checker = 0;

void process ()
{
    clock_t start = clock();
    // system ("trau.exe");
    double r = (double)(clock() - start)/CLOCKS_PER_SEC;
    if (r > ma)
    {
        ma = r;
    }
    TimeS += r;
    system ("work.exe");
}

void PrintSol(bool ok)
{
    if (ok) 
    cout << "Right";
    else 
    cout << "Wrong";
    cout << "\n";
    cout << "Maximum Time: ";
    cout << fixed << setprecision (6) << ma << "\n";
    cout << "Average Time: ";
    cout << fixed << setprecision (6) << TimeS / ntest << "\n";
}