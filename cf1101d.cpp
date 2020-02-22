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

int a[mn];
int pr[mn];
vector<int> vpr;
int ok[mn];
int id[mn];
vector<pair<int, int> > v[mn];
vector<int> e[mn];
int h[mn], hma[mn], hma2[mn];
int sol;

void Dfs (const int& u, const int& w)
{
    hma[u] = hma2[u] = h[u];
    for (const int& v : e[u])
    if (v != w)
    {
        h[v] = h[u] + 1;
        Dfs (v, u);
        if (hma[v] > hma[u])
        {
            hma2[u] = hma[u];
            hma[u] = hma[v];
        }
        else if (hma[v] > hma2[u])
        hma2[u] = hma[v];
    }
    sol = max (sol, hma[u] - h[u] + hma2[u] - h[u] + 1);
}

void eros (const int& n)
{
    for (int i = 2; i * i <= n; ++ i)
    if (!pr[i])
    for (int j = i * i; j <= n; j += i)
    pr[j] = i;
    for (int i = 2; i <= n; ++ i)
    if (!pr[i])
    {
        pr[i] = i;  
        vpr.emplace_back (i);
    }
}

void enter()
{
    int n;
    cin >> n;
    eros (200000);
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        if (a[i] != 1) sol = 1;
    }
    for (int i = 1; i < n; ++ i)
    {
        int u, w;
        cin >> u >> w;
        int c = __gcd (a[u], a[w]);
        while (c != 1)
        {
            int x = pr[c];
            c /= x;
            if (ok[x] == i) continue;
            ok[x] = i;
            v[x].emplace_back(u, w);
        }
    }
    int cn = 0;
    for (const int& i : vpr)
    {
        ++ cn;
        vector<int> V;
        for (auto j : v[i])
        {
            if (id[j.first] != cn)
            V.emplace_back(j.first);
            if (id[j.second] != cn)
            V.emplace_back(j.second);
            id[j.second] = id[j.first] = cn;
            e[j.first].emplace_back(j.second);
            e[j.second].emplace_back(j.first);
        }
        for (const int& u : V)
        if (!h[u])
        {
            h[u] = 1;
            Dfs (u, 0);
        }
        for (const int& u : V)
        {
            h[u] = 0;
            e[u].clear();
        }
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