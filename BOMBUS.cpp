#include <bits/stdc++.h>

#define fn "test"
#define fn1 "BOMBUS"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int sol = 0;
int tr[mn], d[mn], fa[mn];
vector<int> e[mn];
bool ok[mn];
bool dd[mn];
vector<int> V[mn];

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
    d[u] = 1;
    tr[u] = u;
    for (int v : e[u])
    if (v != w)
    {
        fa[v] = u;
        dfs (v, u);
        if (d[v] + 1 > d[u])
        {
            d[u] = d[v] + 1;
            tr[u] = tr[v];
        } 
    }
}

void process (int u)
{
    int v = tr[u];
    int cn = 0;
    while (v)
    {
        dd[v] = 1;
        ++ cn;
        for (int t : e[v])
        if (t != fa[v])
        if (!dd[t])
        V[d[t]].emplace_back(t);
        if (v == u) break;
        v = fa[v];
    }
    sol += cn;
}

void enter()
{
    int n, k;
    read (n); read (k);
    // assert (k != 1);
    for (int i = 1; i < n; ++ i)
    {
        int u, v;
        read (u); read (v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int u = 1;
    queue<int> qu;
    qu.emplace (1);
    while (qu.size())
    {
        u = qu.front();
        qu.pop();
        for (int v : e[u])
        if (!ok[v])
        {
            ok[v] = 1;
            qu.emplace (v);
        }
    }
    dfs (u, 0);
    int ma = d[u];
    V[d[u]].emplace_back(u);
    for (int i = 1; i < 2 * k; ++ i)
    {
        if (!ma) break;
        process (V[ma].back());
        V[ma].pop_back();
        for (; ma && V[ma].empty(); ) -- ma;
    }
    cout << min (sol, n);
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