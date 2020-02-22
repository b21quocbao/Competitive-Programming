#include <bits/stdc++.h>
#define int unsigned long long

#define fn "test"
#define fn1 "CSTATION"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[mn], sc[mn], d1[mn], fa[mn], n, ma = 0;
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

void Dfs (int u, int w)
{
    sc[u] = 1;
    for (const int& v : e[u])
    if (v != w)
    {
        fa[v] = u;
        Dfs (v, u);
        d[u] += sc[v] + d[v];
        sc[u] += sc[v];
    }
}

void Dfs1 (int u, int w)
{
    if (u != 1)
    d1[u] = d1[fa[u]] + n - sc[u] + d[fa[u]] - d[u] - sc[u];
    ma = max (ma, d[u] + d1[u]);
    for (const int& v : e[u])
    if (v != w)
    Dfs1(v, u);
}

void enter()
{
    read (n);
    for (int i = 0; i < n - 1; ++ i)
    {
        int u, v;
        read (u); read (v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    Dfs (1, 0);    
    Dfs1 (1, 0);
    // cerr << d[6] + d1[6];
    for (int i = 1; i <= n; ++ i)
    if ((d[i] + d1[i]) == ma)
    {
        write (i);
        putchar ('\n');
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}