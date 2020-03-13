/*
Code by b21
Time: 19:03 Sun 01/03/2020
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
   else if (ifstream("abc157_b.inp"))
    {
        freopen("abc157_b.inp", "r", stdin);
        freopen("abc157_b.out", "w", stdout);
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

int a[5][5], ok[5][5];

void enter()
{
    for (int i = 0; i < 3; ++ i)
    for (int j = 0; j < 3; ++ j)
    cin >> a[i][j];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        int x;
        cin >> x;
        for (int i = 0; i < 3; ++ i)
        for (int j = 0; j < 3; ++ j)
        if (a[i][j] == x)
        ok[i][j] = 1;
    }
    int sol = 0;
    for (int i = 0; i < 3; ++ i)
    {
        int s = 0;
        for (int j = 0; j < 3; ++ j)
        s += ok[i][j];
        if (s == 3) sol = 1;
    }
    for (int i = 0; i < 3; ++ i)
    {
        int s = 0;
        for (int j = 0; j < 3; ++ j)
        s += ok[j][i];
        if (s == 3) sol = 1;
    }
    if (ok[0][0] && ok[1][1] && ok[2][2]) sol = 1;
    if (ok[0][2] && ok[1][1] && ok[2][0]) sol = 1;
    cout << (sol ? "Yes" : "No");
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