#include <bits/stdc++.h>

#define fn "test"
#define fn1 "NETWORK"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e5) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, m;
int sol[mm];
int far[mn];
int cid1, cid2;
bool ok[mm];
int q;
int k[mn], c[mn], a[mn], b[mn];
int id[mn], id1[mn], id2[mn];
int u[mn], v[mn], w[mn];
int ds[mn], nds;
int cur[mn];
int fa[2 * (int)(1e4) + 10][16];
vector<int> it[mn];
vector<pair<int, int> > e[2 * (int)(1e4) + 10];
int sc[mn], h[mn];
vector<int> co[mn], cor;

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
    for (auto v : e[u])
    if (!h[v.first])
    {
        h[v.first] = h[u] + 1;
        fa[v.first][0] = u;
        dfs (v.first);
        sc[u] += sc[v.first];
    }
}

void udit (int id, int l, int r, int x, int c)
{
    if (l > x || r < x) return;
    if (l == r)
    {
        it[id].emplace_back(c);
        return;
    }
    int m = (l + r) >> 1, i = id * 2;
    udit (i, l, m, x, c);
    udit (i + 1, m + 1, r, x, c);
}

void initit (int id, int l, int r)
{
    if (l == r) return;
    int m = (l + r) >> 1, i = id << 1;
    initit (i, l, m);
    initit (i + 1, m + 1, r);
    it[id].resize(it[i].size() + it[i + 1].size());
    merge (it[i].begin(), it[i].end(), it[i + 1].begin(), it[i + 1].end(), it[id].begin());
}

int quit (int id, int l, int r, int x, int y, int c)
{
    if (l > y || r < x) return 0;
    if (l >= x && r <= y)
    return (int)(upper_bound(it[id].begin(), it[id].end(), c) - it[id].begin());
    int m = (l + r) >> 1, i = id << 1;
    quit (i, l, m, x, y, c);
    quit (i + 1, m + 1, r, x, y, c);
}

void hld (int u)
{
    if (!cur[u]) cur[u] = u;
    ds[u] = ++ nds;
    int V = - 1, w;
    for (auto v : e[u])
    if (h[v.first] > h[u] && (V == - 1 || sc[v.first] > sc[V]))
    {
        V = v.first;
        w = v.second;
    }
    if (V != - 1) 
    {
        cur[V] = cur[u];
        hld (V);
        udit (1, 1, n, ds[V], w);
    }
    for (auto v : e[u])
    if (h[v.first] > h[u] && (v.first != V))
    {
        hld (v.first);
        udit (1, 1, n, ds[v.first], v.second);
    }
}

int qu (int x, int y, int c)
{
    int r = 0;
    while (h[cur[x]] > h[y])
    {
        r += quit (1, 1, n, ds[cur[x]], ds[x], c);
        x = fa[cur[x]][0];
    }
    r += quit (1, 1, n, ds[cur[x]], ds[x], c) - quit (1, 1, n, ds[cur[x]], ds[y], c);
    return r;
}

void initlca ()
{
    for (int i = 1; i <= 14; ++ i)
    for (int u = 1; u <= n; ++ u)
    fa[u][i] = fa[fa[u][i]][i];
}

int lca (int u, int v)
{
    if (h[u] < h[v]) swap (u, v);
    for (int i = 14; i >= 0; -- i)
    if (h[fa[u][i]] >= h[v])  u = fa[u][i];
    if (u == v) return u;
    for (int i = 14; i >= 0; -- i)
    if (fa[u][i] != fa[v][i])
    u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int Fa (int u)
{
    return (far[u] < 0 ? u : far[u] = Fa (far[u]));
}

void uni (int u, int v)
{
    u = Fa (u); v = far[v];
    if (u == v) return;
    if (far[u] > far[v]) swap (u, v);
    far[u] += far[v];
    far[v] = u;
    cor.resize(co[u].size() + co[v].size());
    merge(co[u].begin(), co[u].end(), co[v].begin(), co[v].end(), cor.begin());
    co[u] = cor;
    co[v].clear();
}

void enter()
{
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++ i)
    {
        cin >> u[i] >> v[i] >> w[i];
        id[i] = i;
        e[u[i]].emplace_back(v[i], w[i]);
        e[v[i]].emplace_back(u[i], w[i]);
    }
    for (int i = 0; i < q; ++ i)
    {
        char C;
        cin >> C;
        if (C == 'T')
        {
            cin >> k[i] >> c[i];
            id1[cid1 ++] = i;
        }
        else 
        {
            cin >> a[i] >> b[i] >> c[i];            
            id2[cid2 ++] = i;
        }
    }
    sort (id1, id1 + cid1, [](int i, int j)
         {
             return c[i] < c[j];
         });
    sort (id, id + n - 1, [](int i, int j)
         {
             return w[i] < w[j];
         });
    int K = 0;
    dfs (1);
    memset (far, - 1, sizeof (far));
    for (int i = 1; i <= n; ++ i)
    co[i].emplace_back(h[i]);
    for (int i = 0; i < cid1; ++ i)
    {
        int j = id1[i];
        while (K < n - 1 && w[id[K]] <= c[j])
        uni (u[id[K]], v[id[K ++]]);
        if (h[u[k[j]]] < h[v[k[j]]])
        sol[j] = (int)(cor[Fa (v[k[j]])].lower_bound()
        if (ok[k[j]]) uni (u[k[j]], v[k[j]]);
    }
    h[1] = 1;
    // hld (1);
    // initlca ();
    // initit (1, 1, n);
    // for (int j = 0; j < cid2; ++ j)
    // {
    //     int i = id[j];
    //     int lc = lca (a[i], b[i]);
    //     sol[i] = qu (a[i], lc, c[i]) + qu (b[i], lc, c[i]);
    // }
    for (int i = 0; i < q; ++ i)
    cout << sol[i] << "\n";
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