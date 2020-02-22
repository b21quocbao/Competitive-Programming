/*
Code by b21
Time: 11:19 Sun 20/10/2019
*/

#include <bits/stdc++.h>

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("2010c.inp"))
    {
        freopen("2010c.inp", "r", stdin);
        freopen("2010c.out", "w", stdout);
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

vector<int> e[mn];
int n1, m1, n2, m2, h[mn];
bool ok[mn], win[mn];

void dfs (int u)
{
    ok[u] = 1;
    win[u] = 0;
    for (int v : e[u])
    {
        if (!ok[v]) dfs (v);
        if (!win[v]) win[u] = 1;
    }
    if (win[u])
    {
        h[u] = INT_MAX;
        for (int v : e[u])
        if (!win[v])
        h[u] = min (h[u], h[v] + 1);
    }
    else
    {
        h[u] = 1;
        for (int v : e[u])
        h[u] = max (h[u], h[v] + 1);
    }
}

void enter()
{
    cin >> n1 >> m1;
    for (int i = 0; i < m1; ++ i)
    {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        e[u].emplace_back(v);
    }
    cin >> n2 >> m2;
    for (int i = 0; i < m2; ++ i)
    {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        e[u + n1].emplace_back(v + n1);
    }
    for (int i = 1; i <= n1 + n2; ++ i)
    if (!ok[i]) dfs (i);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++ i)
    {
        int u, v;
        cin >> u >> v;
        v += n1;
        if (win[u] && win[v]) 
        {
            cout << "first\n";
            continue;
        }
        if (!win[u] && !win[v])
        {
            cout << "second\n";
            continue;
        }
        if (win[u] && !win[v])
        cout << (h[u] < h[v] ? "first" : "second") << "\n";
        else 
        cout << (h[u] > h[v] ? "first" : "second") << "\n";
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}