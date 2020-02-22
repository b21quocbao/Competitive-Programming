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
int a[mn], c[mn], u[mn], v[mn];
int fa[mn], b[mn];
vector<int> e[mn];
bool ok[mn];
int n, m, p, k;

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

void dfs (int u, int i, int d)
{
    if (d > k) return;
    ok[u] = 1;
    b[u] |= (1 << i);
    for (int v : e[u])
    if (!ok[v])
    dfs (v, i, d + 1);
}

int Fa (int u)
{
    return (fa[u] < 0 ? u : fa[u] = Fa (fa[u]));
}

inline void uni (int u, int v)
{
    u = Fa (u); v = Fa (v);
    if (u == v) return;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
}

void enter()
{
    read (n); read (m); read (p); read (k);
    for (int i = 0; i < p; ++ i)
    {
        read (a[i]);
        memset (ok, 0, sizeof (ok));
        dfs (a[i], i, 0);
    }
    for (int i = 0; i < p; ++ i)
    read (c[i]);
    for (int i = 0; i < m; ++ i)
    {
        read (u[i]); read (v[i]);
        e[u[i]].emplace_back(v[i]);
        e[v[i]].emplace_back(u[i]);
    }
    for (int i = 0; i < p; ++ i)
    {
        memset (ok, 0, sizeof (ok));
        dfs (a[i], i, 0);
    }
    int s, t;
    long long sol = LLONG_MAX;
    read (s); read (t);
    for (int i = 0; i < (1 << p); ++ i)
    {
        fill_n (fa + 1, n, - 1);
        for (int j = 0; j < m; ++ j)
        if ((b[u[j]] | i) == i && (b[v[j]] | i) == i) 
        uni (u[j], v[j]);
        long long r = 0;
        if (Fa (s) != Fa (t)) continue;
        for (int k = 0; k < p; ++ k)
        if ((i >> k) & 1)
        r += c[k];
        sol = min (sol, r);
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