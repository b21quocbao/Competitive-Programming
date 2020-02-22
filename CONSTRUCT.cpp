#include <bits/stdc++.h>

#define fn "test"
#define fn1 "CONSTRUCT"

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

int fa[mn], f[mn], low[mn], cur[mn], ok[mn];
vector<int> e[mn];
int N;

int F (int u)
{
    if (f[u] != - 1) return f[u];
    low[u] = cur[u] = ++N;
    f[u] = 0;
    for (int v : e[u])
    ok[v] = 0;
    for (int v : e[u])
    ++ ok[v];
    for (int v : e[u])
    if (v != fa[u])
    {
        if (f[v] == - 1) 
        {
            fa[v] = u;
            int r = F (v);
            if (low[v] == cur[v] && ok[v] == 1) 
            ++ r;
            f[u] = max (f[u], r);
        }
        low[u] = min (low[u], low[v]);
    }   
    return f[u];
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
        e[v].emplace_back(u);
    }
    int sol = 0;
    memset (f, - 1, sizeof (f));
    for (int i = 1; i <= n; ++ i)
    sol = max (sol, F (i));
    cout << sol << "\n";
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