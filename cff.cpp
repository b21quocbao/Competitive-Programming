#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

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

int h[mn];
bool ok[mn];
vector<pair<int, int> > e[mn];
pair<int, int> lca[mn][19];
int n;

void Dfs (int u, int w)
{
    for (auto v : e[u])
    if (v.first != w)
    {
        lca[v.first][0] = {u, v.second};
        h[v.first] = h[u] + 1;
        Dfs (v.first, u);
    }
}

void InitLca()
{
    for (int i = 1; i <= 17; ++ i)
    for (int u = 1; u <= n; ++ u)
    {
        lca[u][i].first = lca[lca[u][i - 1].first][i - 1].first;
        lca[u][i].second = max (lca[u][i - 1].second, lca[lca[u][i - 1].first][i - 1].second);
    }
}

int Lca (int u, int v)
{
    if (h[u] < h[v]) swap (u, v);
    int mi = INT_MIN;
    for (int i = 17; i >= 0; -- i)
    if (h[lca[u][i].first] >= h[v])
    {
        mi = max (mi, lca[u][i].second);
        u = lca[u][i].first;
    }
    if (u == v) return mi;
    for (int i = 17; i >= 0; -- i)
    if (lca[u][i].first != lca[v][i].first)
    {
        mi = max (mi, lca[u][i].second);
        mi = max (mi, lca[v][i].second);
        u = lca[u][i].first;
        v = lca[v][i].first;
    }
    mi = max (mi, lca[u][0].second);
    mi = max (mi, lca[v][0].second);
    return mi;
}

int u[mn], id[mn], w[mn], v[mn], fa[mn];

int Fa (int n)
{
    return (fa[n] < 0 ? n : fa[n] = Fa (fa[n]));
}

bool Uni (int u, int v)
{
    u = Fa (u); v = Fa (v);
    if (u == v) return 0;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
    return 1;
}

void enter()
{
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    fa[i] = - 1;
    for (int i = 0; i < m; ++ i)
    {
        cin >> u[i] >> v[i] >> w[i];
        id[i] = i;
    }
    sort (id, id + m, [](int i, int j)
         {
              return w[i] < w[j];
         });
    for (int i = 0; i < m; ++ i)
    {
        int j = id[i];
        if (Uni (u[j], v[j]))
        {
            ok[j] = 1;
            e[u[j]].emplace_back(v[j], w[j]);
            e[v[j]].emplace_back(u[j], w[j]);
        }
    }
    h[1] = 1;
    Dfs (1, 0);
    InitLca();
    int sol = 0;
    for (int i = 0; i < m; ++ i)
    if (!ok[i])
    {
        if (Lca (u[i], v[i]) == w[i]) ++ sol;
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