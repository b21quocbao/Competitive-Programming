#include <bits/stdc++.h>

#define fn "test"
#define fn1 "vertweigh"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<int> e[mn];
int h[mn], fa[mn][17];
int d[mn];
int n;

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

void prelca ()
{
    for (int h = 1; h <= 16; ++ h)
    for (int i = 1; i <= n; ++ i)
    fa[i][h] = fa[fa[i][h - 1]][h - 1];
}

int lca (int u, int v)
{
    if (h[u] < h[v]) swap (u, v);
    for (int i = 16; i >= 0; -- i)
    if (h[fa[u][i]] >= h[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 16; i >= 0; -- i)
    if (fa[u][i] != fa[v][i])
    u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void dfs (int u)
{
    for (int v : e[u])
    if (!h[v])
    {
        h[v] = h[u] + 1;
        fa[v][0] = u;
        dfs (v);
    }
}

void D (int u)
{
    for (int v : e[u])
    if (h[v] > h[u])
    {
        D (v);
        d[u] += d[v];
    }
}

void enter()
{
    int u, v, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++ i)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    h[1] = 1;
    dfs (1);
    prelca ();
    for (int i = 0; i < m; ++ i)
    {
        cin >> u >> v;
        ++ d[u];
        ++ d[v];
        int l = lca (u, v);
        -- d[l];
        -- d[fa[l][0]];
    }
    int sol = 0;
    D (1);
    for (int i = 1;  i <= n; ++i)
    sol = max (sol, d[i]);
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