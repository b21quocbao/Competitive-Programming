#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e4) + 10;
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

vector<int> e[mn];
int h[mn], ma;
int cn[2];
bool color[mn];
bool isleaf[mn], conleaf[mn];

void dfs (const int& u, const int& w)
{
    ++ cn[h[u] % 2];
    ma = max (ma, h[u]);
    if (h[u] % 2)
    color[u] = 1;
    else 
    color[u] = 0;
    for (const int& v : e[u])
    if (v != w)
    {
        isleaf[u] = 0;
        h[v] = h[u] + 1;
        dfs (v, u);
        if (isleaf[v]) conleaf[u] = 0;
    }
    if (isleaf[u]) conleaf[u] = 1;
}

void enter()
{
    ma = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        e[i].clear();
        isleaf[i] = 1;
        conleaf[i] = 1;
    }
    for (int i = 1; i < n; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    cn[0] = cn[1] = 0;
    dfs (1, 0);
    int d = 0;
    if (cn[1] > cn[0]) d = 1;
    int sol = 1;
    if (cn[0] != cn[1]) sol = 2;
    for (int u = 1; u <= n; ++ u)
    {
        int r = 0;
        for (const int& v : e[u])
        if (h[v] > h[u])
        if (color[v] == d) ++ r;
        for (const int& v : e[u])
        if (h[v] > h[u])
        {
            if (r < 2) break;
            if (cn[0] != cn[1] && color[v] == d && r >= 2)
            if (conleaf[v])
            {
                -- r;
                -- cn[d];
                ++ cn[1 - d];
                color[v] = !color[v];
            }
        }
    }
    cout << sol << "\n";
    for (int i = 1; i <= n; ++ i)
    if (color[i])
    cout << i << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++ i)
    if (!color[i])
    cout << i << " ";
    cout << "\n";
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