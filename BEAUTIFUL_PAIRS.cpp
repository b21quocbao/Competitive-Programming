#include <bits/stdc++.h>
 
#define fn "test"
#define fn1 ""
 
using namespace std;
 
const int mn = 1 * (int)(1e5) + 10;
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
 
int st[mn], en[mn], v[mn], h[mn], a[mn], sc[mn], b[mn], fa[mn];
int Num[mn], CnNum, he[mn];
int Time;
vector<int> e[mn];
int n;
vector<int> it[4 * mn];
vector<int> it2[4 * mn];
 
void dfs (int u, int w)
{
    st[u] = ++ Time;
    a[Time] = v[u];
    sc[u] = 1;
    for (const int& v : e[u])
    if (v != w)
    {
        fa[v] = u;
        h[v] = h[u] + 1;
        dfs (v, u);
        sc[u] += sc[v];
    }
    en[u] = Time;
}
 
void InitIt (int id, int l, int r)
{
    if (l == r) 
    {
        it[id].emplace_back(a[l]);
        return;
    }
    int m = (l + r) >> 1, i = id << 1;
    InitIt (i, l, m);
    InitIt (i ^ 1, m + 1, r);
    it[id].resize(r - l + 1);
    merge (it[i].begin(), it[i].end(), it[i ^ 1].begin(), it[i ^ 1].end(), it[id].begin());
}
 
int QuIt (int id, int l, int r, int a, int b, int x, int y)
{
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return 
    upper_bound (it[id].begin(), it[id].end(), y) - lower_bound (it[id].begin(), it[id].end(), x);
    int m = (l + r) >> 1, i = id << 1;
    return QuIt (i, l, m, a, b, x, y) + QuIt (i ^ 1, m + 1, r, a, b, x, y);
}
 
void InitIt2 (int id, int l, int r)
{
    if (l == r) 
    {
        it2[id].emplace_back(b[l]);
        return;
    }
    int m = (l + r) >> 1, i = id << 1;
    InitIt2 (i, l, m);
    InitIt2 (i ^ 1, m + 1, r);
    it2[id].resize(r - l + 1);
    merge (it2[i].begin(), it2[i].end(), it2[i ^ 1].begin(), it2[i ^ 1].end(), it2[id].begin());
}
 
int QuIt2 (int id, int l, int r, int a, int b, int x, int y)
{
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return 
    upper_bound (it2[id].begin(), it2[id].end(), y) - lower_bound (it2[id].begin(), it2[id].end(), x);
    int m = (l + r) >> 1, i = id << 1;
    return QuIt2 (i, l, m, a, b, x, y) + QuIt2 (i ^ 1, m + 1, r, a, b, x, y);
}
 
void ReNum (int u, int U)
{
    Num[u] = ++ CnNum;
    b[CnNum] = v[u];
    he[u] = U;
    int w = - 1;
    for (const int& v : e[u])
    if (h[u] < h[v])
    if ((w == - 1) || (sc[v] > sc[w]))
    w = v;
    if (w != - 1)
    ReNum (w, U);
    for (const int& v : e[u])
    if (h[u] < h[v] && v != w)
    ReNum (v, v);
}
 
 
int lc[mn][17];
 
void InitLca ()
{
    for (int u = 1; u <= n; ++ u)
    lc[u][0] = fa[u];
    for (int i = 1; i <= 16; ++ i)
    for (int u = 1; u <= n; ++ u)
    lc[u][i] = lc[lc[u][i - 1]][i - 1];
}
 
int Lca (int u, int v)
{
    if (h[u] < h[v]) swap (u, v);
    for (int i = 16; i >= 0; -- i)
    if (h[lc[u][i]] >= h[v]) u = lc[u][i];
    if (u == v) return u;
    for (int i = 16; i >= 0; -- i)
    if (lc[u][i] != lc[v][i])
    u = lc[u][i], v = lc[v][i];
    return lc[u][0];
}

 
int Lca2 (int u, int v)
{
    for (int i = 16; i >= 0; -- i)
    if (h[lc[u][i]] > h[v]) u = lc[u][i];
    return u;
}
 
int Qu (int u, int v, int l, int r)
{
    int sol = 0;
    while (he[u] != he[v])
    {
        sol += QuIt2 (1, 1, n, Num[he[u]], Num[u], l, r);
        u = fa[he[u]];
    }
    sol += QuIt2 (1, 1, n, Num[v], Num[u], l, r);
    return sol;
}
 
int QuHld (int u, int V, int l, int r, int lc)
{
    int sol =  Qu (u, lc, l, r) + Qu (V, lc, l, r);
    if (v[u] >= l && v[u] <= r) -- sol; 
    if (v[lc] >= l && v[lc] <= r) -- sol; 
    if (v[V] >= l && v[V] <= r) -- sol; 
    return sol;
}
 
void enter()
{
    int q, p;
    read (n); read (q); read (p);
    for (int i = 1; i <= n; ++ i)
    {
        read (v[i]);
        v[i] %= p;
    }
    for (int i = 1; i < n; ++ i)
    {
        int u, v;
        read (u); read (v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    h[1] = 1;
    dfs (1, 0);
    ReNum (1, 1);
    InitIt(1, 1, n);
    InitIt2 (1, 1, n);
    InitLca();
    long long sol = 0;
    for (int i = 0; i < q; ++ i)
    {
        int a, b, l1, r1, l2, r2;
        read (a); read (b); read (l1); read (r1);
        read (l2); read (r2);
        a ^= sol;
        b ^= sol;
        l1 ^= sol;
        l2 ^= sol;
        r2 ^= sol;
        r1 ^= sol;
        int lc = Lca (a, b);
        int x = QuHld (a, b, l1, r1, lc), y;
        if (a == lc) 
        {
            int z = Lca2 (b, a);
            y = QuIt (1, 1, n, st[1], en[1], l2, r2) - QuIt (1, 1, n, st[z], en[z], l2, r2);
            if (v[a] >= l2 && v[a] <= r2) -- y;
        }
        else 
        y = QuIt (1, 1, n, st[a] + 1, en[a], l2, r2);
        sol = 1ll * x * y;
        write (sol); 
        putchar('\n');
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
    // cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}