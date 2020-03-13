/*
Code by b21
Time: 16:08 Sun 23/02/2020
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
   else if (ifstream("1313a.inp"))
    {
        freopen("1313a.inp", "r", stdin);
        freopen("1313a.out", "w", stdout);
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

void enter()
{
    int a, b, c, sol = 0;
    cin >> a >> b >> c;
    if (a) {
        -- a;
        ++ sol;
    }
    if (b) {
        -- b;
        ++ sol;
    }
    if (c) {
        -- c;
        ++ sol;
    }
    if (a == 1 && b == 1 && c >= 2) {
        -- a;
        -- c;
        -- b;
        -- c;
        sol += 2;
    }
    if (a && b) {
        -- a;
        -- b;
        ++ sol;
    }
    if (a && c) {
        -- a;
        -- c;
        ++ sol;
    }
    if (b && c) {
        -- b;
        -- c;
        ++ sol;
    }
    if (a && b && c) {
        -- a;
        -- b;
        -- c;
        ++ sol;
    }
    cout << sol << "\n";
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