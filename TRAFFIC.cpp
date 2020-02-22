#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TRAFFIC"

using namespace std;

const int mn = 5 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<int> e[mn], g[mn];
int D[mn], f[mn];
int d[mn][mn];

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
    int n, m;
    read (n); read (m);
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        ++ d[u][v];
        if (d[u][v] > 1) continue;
        e[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++ i)
    {
        if (g[i].empty()) D[i] = 1;
        for (int v : e[i])
        D[v] += D[i] * d[i][v];
    }
    f[n] = 1;
    for (int i = n; i >= 1; -- i)
    {
        for (int v : g[i])
        f[v] += f[i] * d[v][i];
    }
    // cerr << D[5];
    int sol = 0;
    for (int u = 1; u <= n; ++ u)
    for (int v = u + 1; v <= n; ++ v)
    if (d[u][v])
    sol = max (sol, D[u] * f[v]);
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