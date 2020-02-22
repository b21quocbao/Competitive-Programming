#include <bits/stdc++.h>

#define fn "test"
#define fn1 "COLORINGPIPE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
list<int> e[mn];
vector<int> v;
vector<vector<int> > sol;
int tr[mn];

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

void Dfs (int u, int w, int Ok = 0)
{
    if (u == w) ++ Ok;
    if (Ok == 2) 
    {
        int ok = 0;
        while (ok != 2)
        {
            v.emplace_back(u);
            if (u == w) ++ ok;
            u = tr[u];
        }
        sol.emplace_back(v);
        return;
    }
    int v = e[u].front();
    e[u].erase (e[u].begin());
    tr[v] = u;
    cerr << u << " " << v << "\n";
    e[v].erase (lower_bound (e[v].begin(), e[v].end(), u));
    Dfs(v, w, Ok);
}

void enter()
{
    int n, m;
    read (n);   read (m);
    for (int i = 0; i < m; ++ i)
    {
        int u, v, c, d;
        read (u); read (v); read (c); read (d);
        if (c != d)
        {
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
    }
    for (int i = 1; i <= n; ++ i)
    if (e[i].size() % 2)
    {
        cout << - 1;
        return;
    }
    for (int i = 1; i <= n; ++ i)
    sort (e[i].begin(), e[i].end());
    // cerr << *lower_bound(e[3].begin(), e[3].end(), 1) << "\n";
    for (int i = 1; i <= n; ++ i)
    {
        v.clear();
        while (e[i].size())
        Dfs (i, i, 0);
    }
    // while (qu.size())
    // {
    //     int u = qu.top().second, x = qu.top().first;
    //     qu.pop();
    //     if (!x) continue;
    //     if (x != e[u].size()) continue;
    //     v.clear();
    //     Dfs (u, u, 0);
    //     qu.emplace (u, e[u].size());
    // }
    write (sol.size()); putchar ('\n');
    for (auto i : sol)
    {
        write (i.size() - 1); putchar (' ');
        for (int j : i)
        {write (j); putchar (' ');}
        putchar ('\n');
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