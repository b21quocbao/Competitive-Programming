#include <bits/stdc++.h>

#define fn "test"
#define fn1 "XORPATH"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int u[mn], v[mn], fa[mn], lc[mn][18], c[mn], chl[mn], nchl, n, sc[mn], da[mn], h[mn], it[4 * mn], q;
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
    sc[u] = 1;
    for (int v : e[u])
    if (!fa[v])
    {
        h[v] = h[u] + 1;
        fa[v] = u;
        lc[v][0] = u;
        dfs (v);
        sc[u] += sc[v];
    }
}

void prelca()
{
    for (int i = 1; i <= 17; ++ i)
    for (int u = 1; u <= n; ++ u)
    lc[u][i]  = lc[lc[u][i - 1]][i - 1];
}



void hld (int u, int x)
{
    int V = 0;
    chl[u] = ++ nchl;
    if (!x) x = u;
    da[u] = x; 
    for (int v : e[u])
    if (v != fa[u] && sc[v] > sc[V]) V = v;
    if (V) hld (V, x);
    for (int v : e[u])
    if (v != fa[u] && v != V)
    hld (v, 0);
}

pair<int, int> lca (int u, int v)
{
    for (int i = 17; i >= 0; -- i)
    if (h[lc[u][i]] > h[v]) u = lc[u][i];
    if (fa[u] == v) return {u, 0}; 
    if (h[fa[u]] == h[v]) u = fa[u];
    for (int i = 17; i >= 0; -- i)
    if (lc[u][i] != lc[v][i])
    u = lc[u][i], v = lc[v][i];
    return {u, v};
}

void ud (int id, int a, int b, int x, int d)
{
    if (a > x || b < x) return;
    if (a == b)
    {
        it[id] = d;
        return;
    }
    int m = (a + b) >> 1;
    ud (id << 1, a, m, x, d);
    ud ((id << 1) ^ 1, m + 1, b, x, d);
    it[id] = it[id << 1] ^ it[(id << 1) ^ 1]; 
}

int qu (int id, int a, int b, int x, int y)
{
    if (a > y || b < x) return 0;
    if (a >= x && b <= y) return it[id];
    int m = (a + b) >> 1;
    return qu (id << 1, a, m, x, y) ^ qu ((id << 1) ^ 1, m + 1, b, x, y);
}

int query (int u, int v)
{
    if (!v) return 0;
    int sol = 0;
    while (h[da[u]] > h[v])
    {
        sol ^= qu (1, 1, n, chl[da[u]], chl[u]);
        u = fa[da[u]];
    }
    sol ^= qu (1, 1, n, chl[v], chl[u]);
    return sol;
}

void enter()
{
    cin >> n >> q;
    for (int i = 1; i <= n - 1; ++ i)
    {
        cin >> u[i] >> v[i] >> c[i];
        e[u[i]].push_back(v[i]);
        e[v[i]].push_back(u[i]);
    }
    fa[1] = 1;
    dfs (1);
    hld (1, 0);
    prelca ();
    for (int i = 1; i <= n - 1; ++ i)
    {
        if (u[i] == fa[v[i]]) swap (u[i], v[i]);
        ud (1, 1, n, chl[u[i]], c[i]);
    }
    for (int i = 0; i < q; ++ i)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1)
        {
            c[x] = y;
            ud (1, 1, n, chl[u[x]], c[x]);
        }
        else 
        {
            if (h[x] < h[y]) swap (x, y);
            auto lc = lca (x, y);
            cout << (query (x, lc.first) ^ query (y, lc.second))  << "\n";
        }
    }
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