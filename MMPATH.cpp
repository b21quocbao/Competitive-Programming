#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MMPATH"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
int n, q;
int h[mn];
int x[mn];
bool ok[mn];
int cn = 0;
int cha[mn];
int d[mn][17], fa[mn][17];

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


struct Z
{
    int x, i, j;
    Z (){}
    Z (int X, int I, int J)
    {
        x = X; i = I; j = J;
    }
};


struct cmp
{
    bool operator () (Z a, Z b) const
    {
        return a.x > b.x;
    }
} myc;

int Id (int i, int j)
{
    return (i - 1) * n + j;
}

int Lca (int u, int v)
{
    if (h[u] < h[v]) swap (u, v);
    int r = INT_MAX;
    for (int i = 16; i >= 0; -- i)
    if (fa[u][i] > 0 && h[fa[u][i]] >= h[v])
    {
        r = min (r, d[u][i]);
        u = fa[u][i];
    }
    if (u == v) return min (r, x[u]);
    for (int i = 16; i >= 0; -- i)
    if (fa[u][i] != fa[v][i])
    {
        r = min (r, min (d[u][i], d[v][i]));
        u = fa[u][i], v = fa[v][i];
    }
    u = fa[u][0];
    return min (r, x[u]);
}

int Fa (int u)
{
    return (cha[u] <= 0 ? u : cha[u] = Fa (cha[u]));
}

bool kt (int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int H (int u)
{
    if (u <= 0) return 0;
    if (h[u]) return h[u];
    return h[u] = H (fa[u][0]) + 1;
}

void enter()
{
    cin >> n >> q;
    vector<Z> v;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> x[Id (i, j)];
        v.emplace_back(x[Id (i, j)], i, j);
        fa[Id (i, j)][0] = - 1;
        d[Id (i, j)][0] = x[Id (i, j)];
    }   
    sort (v.begin(), v.end(), myc);
    for (auto u : v)
    for (int h = 0; h < 4; ++ h)
    {
        int i = u.i + hx[h], j = u.j + hy[h];
        ok[Id (u.i, u.j)] = 1;
        if (kt (i, j) && ok[Id (i, j)] && Fa (Id (i, j)) != Fa (Id (u.i, u.j)))
        {
            fa[Fa (Id (i, j))][0] = Id (u.i, u.j);
            cha[Fa (Id (i, j))] = Id (u.i, u.j);
        }
    }
    for (int h = 1; h <= 16; ++ h)
    for (int u = Id (1, 1); u <= Id (n, n); ++ u)
    {
        fa[u][h] = fa[fa[u][h - 1]][h - 1];
        if (fa[u][h] < 0)
        {
            fa[u][h] = 0;
            continue;
        }
        d[u][h] = min (d[u][h - 1], d[fa[u][h - 1]][h - 1]);
    }
    for (int u = Id (1, 1); u <= Id (n, n); ++ u)
    {
        H (u);
    }
    for (int i = 0; i < q; ++ i)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << Lca (Id (x, y), Id (u, v)) << "\n";
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