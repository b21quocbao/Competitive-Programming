/*
Code by b21
Time: 21:34 Wed 04/03/2020
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mn = 1 * (int)(1e6) + 10;
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
   else if (ifstream("1316d.inp"))
    {
        freopen("1316d.inp", "r", stdin);
        freopen("1316d.out", "w", stdout);
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
    
}

int n, m, p;
int a[mn], b[mn];

void solve()
{
    read (n); read (m); read (p);
    for (int i = 0; i < n; ++ i)
    read (a[i]);
    for (int i = 0; i < m; ++ i)    
    read (b[i]);
    int ok1 = - 1, ok2 = - 1;
    for (int i = 0; i < max (n, m); ++ i)
    {
        if (a[i] % p && ok1 == - 1) ok1 = i;
        if (b[i] % p && ok2 == - 1) ok2 = i;
    }
    cout << ok1 + ok2;
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