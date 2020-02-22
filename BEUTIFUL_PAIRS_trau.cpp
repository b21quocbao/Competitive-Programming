#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

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

int fa[mn], h[mn];
vector<int> e[mn];

void dfs (int u, int w)
{
    for (int v : e[u])
    if (v != w)
    {
        fa[v] = u;
        h[v] = h[u] + 1;
        dfs (v, u);
    }
}

int v[mn];

bool kt (int x, int y, int z)
{
    while (x != y)
    {
        if (x == z || y == z) return 1;
        if (h[x] > h[y]) x = fa[x];
        else y = fa[y];
    }
    return 0;
}

void enter()
{
    int n, q, p;
    cin >> n >> q >> p;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> v[i];
        v[i] %= p;
    }
    for (int i = 1; i < n; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs (1, 0);
    int sol = 0;
    for (int i = 0; i < q; ++ i)
    {
        int a, b, l1, r1, l2, r2;
        cin >> a >> b >> l1 >> r1 >> l2 >> r2;
        // a ^= sol;
        // b ^= sol;
        // l1 ^= sol;
        // l2 ^= sol;
        // r2 ^= sol;
        // r1 ^= sol;
        sol = 0;
        for (int x = 1; x <= n; ++ x)
        for (int y = 1; y <= n; ++ y)
        if (x != y && x != a && x != b)
        if (y != x && y != a && y != b)
        if (v[x] >= l1 && v[x] <= r1)
        if (v[y] >= l2 && v[y] <= r2)
        if (kt (a, b, x) && kt (x, y, a)) ++ sol;
        cout << sol << "\n";
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