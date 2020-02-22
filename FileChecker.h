#include <bits/stdc++.h>

using namespace std;
const int N = (int)(1e5) + 10;
int sol[N], l[N], r[N], sol1[N], s[2 * N][2];

bool work1 ()
{
    //1 la sai 0 la dung
    ifstream in ("test.inp");
    ifstream ou ("test.out");
    ifstream an ("test.ans");
    ofstream to ("taotest.out", ofstream::app);
    //xoa tu day
    int sol1, sol2;
    ou >> sol1;
    an >> sol2;
    if (sol1 != sol2) return 1;
    int n;
    in >> n;
    deque<int> a;
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        in >> x;
        a.emplace_back(x);
    }
    int cur = 0;
    for (int i = 0; i < sol1; ++ i)
    {
        char c;
        if (!(an >> c)) return 1;
        int x;
        if (c == 'L') 
        {
            x = a.front();
            a.pop_front();
        } 
        else
        {
            x = a.back();
            a.pop_back();
        }
        if (x <= cur) return 1;
        cur = x;
    }
    return 0;
}
