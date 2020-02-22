#include <bits/stdc++.h>

#define fn "test"
#define fn1 "treecol"

using namespace std;

const int mn = 5 * (int)(1e3) + 10;
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

int f2[mn][mn], f1[mn][mn], f0[mn], sc[mn];
vector<int> e[mn];

void Dfs (const int& u, const int& w)
{
    sc[u] = f0[u] = f2[u][0] = f1[u][0] = 0;
    for (const int& v : e[u])
    {
        if (v == w) continue;
        Dfs (v, u);
        int ma = f0[v] + 1;
        for (int i = sc[u] + 1; i <= sc[u] + sc[v]; ++ i)
        f1[u][i] = 0;
        for (int i = 0; i <= sc[v]; ++ i)
        {
            ma = max (ma, f1[v][i] + i);
            for (int j = 0; j <= sc[u]; ++ j)
            f1[u][i + j] = max (f1[u][i + j], j * i + f2[u][j] + f1[v][i]);
        }
        for (int i = 0; i <= sc[u]; ++ i)
        f1[u][i + 1] = max (f1[u][i + 1], i + f2[u][i] + f0[v]);
        f0[u] += ma;
        sc[u] += sc[v];
        for (int i = 0; i <= sc[u]; ++ i)
        f2[u][i] = f1[u][i];
    }
    if (!sc[u]) 
    {
        ++ sc[u];
        f1[u][1] = 0;
    }
}

void enter()
{
    int n;
    cin >> n;
    // memset (f1, 0, sizeof (f1));
    for (int i = 1; i <= n; ++ i)
    e[i].clear();
    for (int i = 1; i < n; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    Dfs (1, 0);
    int sol = f0[1];
    for (int i = 0; i <= sc[1]; ++ i)
    sol = max (sol, f1[1][i]);
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}