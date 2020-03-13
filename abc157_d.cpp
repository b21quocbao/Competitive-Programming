/*
Code by b21
Time: 19:17 Sun 01/03/2020
*/

#include <bits/stdc++.h>

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("abc157_d.inp"))
    {
        freopen("abc157_d.inp", "r", stdin);
        freopen("abc157_d.out", "w", stdout);
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

set<int> e[mn];
int fa[mn];

int Fa (int u) {
    return (fa[u] < 0 ? u : fa[u] = Fa (fa[u]));
}

void Uni (int u, int v) {
    if (u == v) return;
    if (fa[v] > fa[u]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
}

void enter()
{
    int n, m, k;
    cin >> n >> m >> k;
    memset (fa, - 1, sizeof (fa));
    for (int i = 0; i < m; ++ i) {
        int u, v;
        cin >> u >> v;
        Uni (Fa (u), Fa (v));
        e[u].emplace(v);
        e[v].emplace(u);
    }
    for (int i = 0; i < k; ++ i) {
        int u, v;
        cin >> u >> v;
        e[u].emplace(v);
        e[v].emplace(u);
    }
    for (int i = 1; i <= n; ++ i)
    {
        int sol = - fa[Fa (i)];
        for (int j : e[i])
        if (Fa (i) == Fa (j)) -- sol;
        cout << sol - 1 << " ";
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