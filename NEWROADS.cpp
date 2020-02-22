#include <bits/stdc++.h>
#define int long long 

#define fn "test"
#define fn1 "NEWROADS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int num[mn], low[mn], te[mn], ok[mn], sc[mn];
int ti, cn;
vector<int> v;
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

void dfs (int u, int w)
{
    num[u] = low[u] = ++ ti;
    v.emplace_back(u);
    for (int v : e[u])
    if (v != w)
    {
        if (!num[v])
        {
            dfs (v, u);
            low[u] = min (low[u], low[v]);
        }
        else low[u] = min (low[u], low[v]);
    }
    if (low[u] == num[u])
    {
        ++ cn;
        while (1)
        {
            int x = v.back();
            v.pop_back();
            ok[x] = cn;
            ++ sc[cn];
            num[x] = low[x] = INT_MAX;
            if (x == u) break;
        }
    }
}

void enter()
{
    int n, m;
    read (n); read (m);
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        if (u == v) continue;
        e[u].emplace_back(v);
    }
    for (int i = 1; i <= n; ++ i)
    {
        sort (e[i].begin(), e[i].end());
        e[i].resize(unique (e[i].begin(), e[i].end()) - e[i].begin());
    }
    for (int i = 1; i <= n; ++ i)
    if (!num[i])
    dfs (i, 0);
    for (int u = 1; u <= n; ++ u)
    for (int v : e[u])
    if (ok[u] == ok[v])
    ++ te[ok[u]];
    long long sol = 0;
    for (int i = 1; i <= cn; ++ i)
    sol += 1ll * sc[i] * (sc[i] - 1) - te[i];
    cout << sol;
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}