/*
Code by b21
Time: 21:55 Thu 20/06/2019
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
   else if (ifstream("028d.inp"))
    {
        freopen("028d.inp", "r", stdin);
        freopen("028d.out", "w", stdout);
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

char s[110][110];

void enter()
{
    int r, c, k;
    cin >> r >> c >> k;
    for (int i = 1; i <= r; ++ i)
    for (int j = 1; j <= c; ++ j)
    s[i][j] = '.';
    for (int i = 0; i < k; ++ i)
    {
        char C;
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2 >> C;
        for (int t = r1; t <= r2; ++ t)
        for (int l = c1; l <= c2; ++ l)
        s[t][l] = C;
    }
    for (int i = 1; i <= r; ++ i)
    {
        for (int j = 1; j <= c; ++ j)
        cout << s[i][j];
        cout << "\n";
    }

    
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}