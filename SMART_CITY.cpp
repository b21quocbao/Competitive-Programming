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

vector<pair<int, int> > e[mn];
int h[mn], sc[mn], a[mn], b[mn], fa[mn], he[mn], Num[mn], Cn;
int n, q;

void dfs (int u, int w)
{
    sc[u] = 1;
    for (const auto& v : e[u])
    if (v.first != w)
    {
        h[v.first] = h[u] + 1;
        fa[v.first] = u;
        a[v.first] = v.second;
        dfs (v.first, u);
        sc[u] += sc[v.first];
    }
}

void ReNum (int u, int U)
{
    int w = - 1;
    he[u] = U;
    Num[u] = ++ Cn;
    b[Cn] = a[u];
    for (const auto& v : e[u])
    if (v.first != fa[u])
    if (w == - 1 || sc[v.first] > sc[w]) w = v.first;
    if (w != - 1) ReNum (w, U);
    for (const auto& v : e[u])
    if (v.first != fa[u] && v.first != w)
    ReNum (v.first, v.first);
}

vector<int> it[4 * mn];

void InitIt (int id, int l, int r)
{
    if (l == r) 
    {
        it[id].emplace_back(b[l]);
        return;
    }
    int m = (l + r) >> 1, i = id << 1;
    InitIt (i, l, m);
    InitIt (i ^ 1, m + 1, r);
    it[id].resize(r - l + 1);
    merge (it[i].begin(), it[i].end(), it[i ^ 1].begin(), it[i ^ 1].end(), it[id].begin());
}

int qu (int id, int l, int r, int a, int b, int x)
{
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return upper_bound(it[id].begin(), it[id].end(), x) - it[id].begin();
    int m = (l + r) >> 1, i = id << 1;
    return qu (i, l, m, a, b, x) + qu (i ^ 1, m + 1, r, a, b, x);
}

int Lca (int u, int v)
{
    while (he[u] != he[v])
    if (h[he[u]] > h[he[v]]) u = fa[he[u]];
    else v = fa[he[v]];
    return (h[u] > h[v] ? v : u);
}

int Tr (int u, int v, int c)
{
    int sol = 0;
    while (he[u] != he[v])
    sol += qu (1, 1, n, Num[he[u]], Num[u], c), u = fa[he[u]];
    sol += qu (1, 1, n, Num[v] + 1, Num[u], c);
    return sol;
}

int Qu (int u, int v, int c)
{
    int lc = Lca (u, v);
    return Tr (u, lc, c) + Tr (v, lc, c);
}

void enter()
{
    cin >> n >> q;
    for (int i = 1; i < n; ++ i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    dfs (1, 0);
    ReNum (1, 1);
    InitIt (1, 1, n);
    for (int i = 0; i < q; ++ i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        cout << Qu (u, v, c) << "\n";
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