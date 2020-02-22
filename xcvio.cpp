/*
Code by b21
Time: 10:57 Sun 10/11/2019
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
   else if (ifstream("xcvio.inp"))
    {
        freopen("xcvio.inp", "r", stdin);
        freopen("xcvio.out", "w", stdout);
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

bool ok[mn];
vector<int> e[mn];
bool Ok;
int U;

void dfs (int u, int w)
{
    ok[u] = 1;
    for (int v : e[u])
    if (v != U)
    if (ok[v] && v != w) Ok = 0;
    for (int v : e[u])
    if (v != U)
    if (!ok[v]) dfs (v, u);
}

void enter()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    e[i].clear();
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if (m == n - 1)
    {
        cout << - 1;
        return;
    }
    for (U = 1; U <= n; ++ U)
    {
        fill_n (ok + 1, n, 0);
        Ok = 1;
        for (int i = 1; i <= n; ++ i)
        if (i != U && !ok[i])
        dfs (i, 0);
        if (Ok)
        {
            cout << U;
            return;
        }
    }
    cout << - 1;
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

main()
{
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}