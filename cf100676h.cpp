#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int low[mn], num[mn], Time;
vector<int> V;
vector<pair<int, int> > E[mn], e[mn];
int cn;
int d[mn], d1[mn], d2[mn];

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
    low[u] = num[u] = ++ Time;
    V.emplace_back(u);
    for (auto v : E[u])
    if (v.first != w)
    {
        if (!num[v.first])
        Dfs (v.first, u);
        low[u] = min (low[u], low[v.first]);
    }
    if (low[u] == num[u])
    {
        ++ cn;
        int U = u;
        while (1)
        {
            int u = V.back();
            V.pop_back();
            d[u] = cn;
            num[u] = low[u] = base;
            if (u == U) break;
        }
    }
}

void dfs (int u, int w)
{
    int ma1 = 0, ma2 = 0, i1;
    for (auto v : e[u])
    if (v.first != w)
    {
        dfs (v.first, u);
        d1[u] = max (d1[u], d1[v.first] + v.second);
        if (!ma1 || d1[v.first] + v.second > ma1)
        {
            ma2 = ma1;
            ma1 = d1[v.first] + v.second;
            i1 = v.first;
        }
        else ma2 = max (ma2, d1[v.first] + v.second);
    }
    for (auto v : e[u])
    if (v.first != w)
    {
        if (v.first != i1)
        d2[v.first] = ma1 + v.second;
        else if (ma2)
        d2[v.first] = ma2 + v.second;
    }
}

void dfs2 (int u, int w)
{
    for (auto v : e[u])
    if (v.first == w)
    d2[u] = max (d2[u], d2[v.first] + v.second);
    for (auto v : e[u])
    if (v.first != w)
    dfs2 (v.first, u);
}

void enter()
{
    int n, m;
    read (n); read (m);
    cn = Time = 0;
    V.clear();
    for (int i = 1; i <= n; ++ i)
    {
        e[i].clear();
        E[i].clear();
        d2[i] = d1[i] = num[i] = low[i] = 0;
    }
    for (int i = 0; i < m; ++ i)
    {
        int u, v, w;
        read (u); read (v); read (w);
        E[u].emplace_back(v, w);
        E[v].emplace_back(u, w);
    }
    Dfs (1, 0);
    for (int u = 1; u <= n; ++ u)
    for (auto v : E[u])
    {
        if (d[v.first] != d[u])
        e[d[u]].emplace_back (d[v.first], v.second);
    }
    dfs (d[1], 0);
    dfs2 (d[1], 0);
    int sol = LLONG_MAX, soli;
    for (int i = 1; i <= n; ++ i)
    if (max (d1[d[i]], d2[d[i]]) < sol)
    {
        sol = max (d1[d[i]], d2[d[i]]);
        soli = i;
    }
    cout << soli << " " << sol << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}