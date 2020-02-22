#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SURROUND"

using namespace std;

const int mn = 2 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, k;
int d[mn][21];

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

void PreRmq()
{
    for (int i = 1; i <= 20; ++ i)
    for (int u = 1; u <= (n << 1); ++ u)
    d[u][i] = d[d[u][i - 1]][i - 1];
}

void enter()
{
    read (n); read (k);
    for (int i = 0; i < k; ++ i)
    {
        int u, v;
        read (u); read (v);
        ++ v;
        if (v <= u)
        d[u][0] = max (d[u][0], v + n);
        else
        {
            d[u][0] = max (d[u][0], v);
            d[u + n][0] = max (d[u + n][0], v + n);
        }
    }
    for (int u = 1; u <= (n << 1); ++ u)
    {
        d[u][0] = max (d[u - 1][0], d[u][0]);
        if (d[u][0] < u) d[u][0] = 0;
    }
    PreRmq ();
    int sol = - 1;
    for (int i = 1; i <= n; ++ i)
    {
        int s = 0, k = i;
        for (int j = 20; j >= 0; -- j)
        if (d[k][j] && d[k][j] < i + n)
        {
            k = d[k][j];
            s ^= (1 << j);
        }
        k = d[k][0];
        ++ s;
        if (k >= i + n)
        sol = (sol == - 1 ? s : min (sol, s));
    }
    if (sol == - 1)
    cout << "Impossible";
    else
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