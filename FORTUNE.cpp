#include <bits/stdc++.h>

#define fn "test"
#define fn1 "FORTUNE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, k, fa[mn], out[mn], w[mn], W[mn];
int Time;
int d[mn][mm];
vector<int> e[mn];

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

void dfs (int u)
{
    int r = Time;
    for (const int& v : e[u])
    dfs (v);
    out[++ Time] = r;
    W[Time] = w[u];
}

void enter()
{
    Time = 0;
    read (n); read (k);
    for (int i = 0; i <= n; ++ i)
    e[i].clear();
    for (int i = 1; i <= n; ++ i)
    {
        read (fa[i]); read (w[i]);
        e[fa[i]].emplace_back(i);
    }
    dfs (0);
    for (int j = 1; j <= k; ++ j)
    d[0][j] = - 1;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= k; ++ j)
    {
        d[i][j] = d[i - 1][j];
        if (d[out[i]][j - 1] != - 1) 
        d[i][j] = max (d[i][j], d[out[i]][j - 1] + W[i]);
    }
    if (d[n][k] == - 1) d[n][k] = 0;
    write (d[n][k]);
    putchar('\n');
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
