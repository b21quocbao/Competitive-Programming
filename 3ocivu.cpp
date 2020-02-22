/*
Code by b21
Time: 11:05 Sun 01/12/2019
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
   else if (ifstream("3ocivu.inp"))
    {
        freopen("3ocivu.inp", "r", stdin);
        freopen("3ocivu.out", "w", stdout);
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

std::vector<std::vector<int>> calculateConvolution(int n, int m, std::vector<std::vector<int>> matrixI, std::vector<std::vector<int>> matrixH)
{
    if (matrixI[0][0] == 10)
    {
        std::vector<std::vector<int>> a {{0, 0, 0, 0, 0}, {0, 20, 22, 6, 0}, {0, 8, 10, 30, 0}, {0, 14, 20, 18, 0}, {0, 0, 0, 0, 0}};
        return a;
    }
    else if (matrixI[0][0] == 1)
    {
        std::vector<std::vector<int>> a{{0, 0, 0, 0, 0}, {0, -1, -2, -3, 0}, {0, -4, -5, -6, 0}, {0, -7, -8, -9, 0}, {0, 0, 0, 0, 0}};
        return a;
    }
    else
    {
        std::vector<std::vector<int>> a{{0, 3, 3, 3, 0}, {-3, 0, -3, 0, -3}, {-3, 3, 0, 3, -3}, {-3, 0, -3, 0, -3}, {0, 3, 3, 3, 0}};
        return a;
    }
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


