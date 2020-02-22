#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, m, w;
vector<pair<int, int> > e[mn];
int d[mn][mn];
bool ok[mn];

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

bool dfs (int U)
{
    queue<int> qu;
    ok[U] = 1;
    qu.emplace(U);
    vector<int> l;
    while (qu.size())
    {
        int u = qu.front(); qu.pop();
        l.emplace_back(u);
        for (auto v : e[u])
        if (!ok[v.first]) 
        {
            ok[v.first] = 1;
            qu.emplace(v.first);
        }
    }
    for (int i = 0; i <= l.size(); ++ i)
    for (int u : l)
    for (auto v : e[u])
    d[U][v.first] = min (d[U][v.first], d[U][u] + v.second);
    for (int u : l)
    for (auto v : e[u])
    if (d[U][u] + v.second < d[U][v.first])
    return 1;
    if (x < min1)
    {
        min3 = min2;
        min2 = min1;
        min1 = x;
    }
    else if (x < min2)
    {
        
    }
    return 0;
}

void enter()
{
    cin >> n >> m >> w;
    memset (d, 0x7f, sizeof (d));
    memset (ok, 0, sizeof (ok));
    for (int i = 1; i <= n; ++ i)
    {
        d[i][i] = 0;
        e[i].clear();
    }
    for (int i = 0; i < m; ++ i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    for (int i = 0; i < w; ++ i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, - w);
    }
    for (int i = 1; i <= n; ++ i)
    if (!ok[i])
    if (dfs (i))
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}