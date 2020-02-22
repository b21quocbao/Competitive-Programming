#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n;
pair<int, long long> fa[mn][19];
vector<pair<int, int> > e[mn];
int d[mn];
int a[mn];

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
    for (auto v : e[u])
    {
        fa[u][0] = v;
        dfs (v.first);
    }
}

void initlca ()
{
    for (int i = 1; i <= 18; ++ i)
    for (int u = 1; u <= n; ++ u)
    {
        fa[u][i].first = fa[fa[u][i - 1].first][i - 1].first;
        fa[u][i].second = fa[u][i - 1].second + fa[fa[u][i - 1].first][i - 1].second;
    }
}

void dfs1 (int u)
{
    for (auto v : e[u])
    if (v.first != fa[u][0].first)
    {
        dfs1 (v.first); 
        d[u] += d[v.first];
    }
}

void enter()
{
    read (n);
    for (int i = 1; i <= n; ++ i)
    read (a[i]);
    for (int i = 1; i < n; ++ i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back (v, w);
        e[v].emplace_back (u, w);
    }
    dfs (1);
    initlca();
    for (int i = 1; i <= n; ++ i)
    {
        int k = i;
        long long r = 0;
        for (int j = 18; j >= 0; -- j) 
        if (fa[k][j].first && r + fa[k][j].second <= a[i])
        {
            r += fa[k][j].second;
            k = fa[k][j].first;
        }
        ++ d[k];
        -- d[fa[k][0].first];
    }
    dfs1 (1);
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