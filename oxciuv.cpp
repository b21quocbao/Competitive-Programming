/*
Code by b21
Time: 11:05 Sun 08/12/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("oxciuv.inp"))
    {
        freopen("oxciuv.inp", "r", stdin);
        freopen("oxciuv.out", "w", stdout);
    }
}

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
void write (T a)
{
    if (a < 0)
    {
        putchar ('-');
        write (-a);
        return;
    }
    if (a < 10)
    {
        putchar ('0' + a);
        return;
    }
    write (a / 10);
    putchar ((char)('0' + (a % 10)));
}


int hx[8] = {0, 0, 1, 1, 1, - 1, - 1, - 1};
int hy[8] = {1, - 1, - 1, 0, 1, - 1, 0, 1};
std::vector<std::vector<long long>> findTheGabageBin(int inN, int inM, std::vector<std::vector<long long>> map)
{
    for (int x = 0; x < inN; ++ x)
    for (int y = 0; y < inN; ++ y)
    if (!map[x][y])
    for (int i = 0; i < 8; ++ i)
    {
        int X = x + hx[i], Y = y + hy[i];
        if (X < 0 || X >= inN) continue;
        if (Y < 0 || Y >= inM) continue;
        if (map[X][Y] == 1000) ++ map[x][y];
    }
    return map;
}



void enter()
{
}

void solve()
{

}

void print_result()
{

}

main()
{
    docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}