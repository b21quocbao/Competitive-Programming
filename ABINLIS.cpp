#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ABINLIS"

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int m, n, a[mn], b[mn], d1[mn], d[mn], d2[mn];

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
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
    read (m);
    int cn = 0;
    for (int i = 1; i <= m; ++ i)
    {
        read (a[i]);
        cn += (1 - a[i]);
        if (!d[cn]) d[cn] = i;
    }
    for (int i = m; i >= 1; -- i)
    d1[i] = d1[i + 1] + a[i];
    read (n);
    for (int i = 1; i <= n; ++ i)
    {
        read (b[i]);
    }
    int sol = 0;
    cn = 0;
    for (int i = n; i >= 1; -- i)
    d2[i] = d2[i + 1] + b[i];
    sol = max (sol, min (d1[1], d2[1]));
    for (int i = 1; i <= n; ++ i)
    {
        if (!b[i]) ++ cn;
        if (cn && !d[cn]) break;
        sol = max (sol, cn + min (d1[d[cn] + 1], d2[i + 1]));
    }
    cout << sol;
}

void solve()
{

}

void print_result()
{

}

int main()
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