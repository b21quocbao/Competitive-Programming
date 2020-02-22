#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TRANFOOD"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long g[mn];
int fa[mn], sc[mn], f[mn], sc1[mn];
long long d[mn], d1[mn];
vector<pair<int, int> > e[mn];
int n, s;

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

void dfs (int u, int w)
{ 
    sc[u] = g[u];
    for (auto v : e[u])
    {
        if (v.first == w) continue;
        fa[v.first] = u;
        f[v.first] = v.second;
        dfs (v.first, u);
        sc[u] += sc[v.first];
        d[u] += d[v.first] + 1ll * v.second * sc[v.first];
    }
}

void dfs2 (int u, int w)
{
    sc1[u] = g[u];
    if (u != 1)
    {
        d1[u] = d1[fa[u]] + 1ll * (s - sc[u]) * f[u];
        d1[u] += d[fa[u]] - d[u] - 1ll * sc[u] * f[u];
    }
    for (auto v : e[u])
    {
        if (v.first == w) continue;
        dfs2 (v.first, u);
    }
}

void enter()
{
    read (n);
    for (int i = 1; i < n; ++ i)
    {
        int u, v, w;
        read (u); read (v); read (w);
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);        
    }
    for (int i = 1; i <= n; ++ i)
    {
        read (g[i]);
        s += g[i];
    }
    long long sol1 = LLONG_MAX;
    long long sol2 = LLONG_MIN;
    dfs (1, 0);
    dfs2 (1, 0);
    for (int i = 1; i <= n; ++ i)
    {
        sol1 = min (sol1, d[i] + d1[i]);
        sol2 = max (sol2, d[i] + d1[i]);
    }
    cout << sol1 << " " << sol2;
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