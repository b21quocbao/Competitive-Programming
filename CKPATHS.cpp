#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "CKPATHS"

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

int w[mm], sc[mm];
long long f1[mm][mm], f2[mm][mm], f3[mm][mm], f0[mm][mm], f4[mm][mm];
vector<int> e[mm];

void Dfs (const int& u, const int& W)
{
    f2[u][0] = f0[u][0] = 0;
    for (const int& v : e[u])
    {
        if (v == W) continue;
        Dfs (v, u);
        for (int j = sc[u]; j >= 1; -- j) 
        for (int i = 0; i <= sc[v]; ++ i)
        f1[u][i + j] = max (f1[u][i + j], f1[u][j] + f0[v][i]);
        for (int i = sc[u]; i >= 1; -- i)
        for (int j = 0; j <= sc[v]; ++ j)
        f3[u][i + j] = max (f3[u][i + j], f3[u][i] + max (f0[v][j], f1[v][j]));
        for (int i = 0; i <= sc[v]; ++ i)
        for (int j = 0; j <= sc[u]; ++ j)
        {
            if (i)
            {
                f1[u][i + j] = max (f1[u][i + j], f2[u][j] + f1[v][i] + w[u]);
                if (j)
                f3[u][i + j - 1] = max (f3[u][i + j - 1], f4[u][j] + w[u] + f1[v][i]);
            }
            f0[u][i + j] = max (f0[u][i + j], f2[u][j] + max (f1[v][i], f0[v][i]));
        }
        for (int i = sc[u]; i >= 1; -- i)
        for (int j = 0; j <= sc[v]; ++ j)
        f4[u][i + j] = max (f4[u][i + j], f4[u][i] + max (f0[v][j], f1[v][j]));
        for (int i = 0; i <= sc[u]; ++ i)
        for (int j = 1; j <= sc[v]; ++ j)
        f4[u][i + j] = max (f4[u][i + j], f2[u][i] + f1[v][j]);
        sc[u] += sc[v];
        for (int i = 0; i <= sc[u]; ++ i)
        f2[u][i] = f0[u][i];
    }
    ++ sc[u];
    for (int i = 0; i < sc[u]; ++ i)
    {
        f1[u][i + 1] = max (f1[u][i + 1], f0[u][i] + w[u]);
        f0[u][i] = max (f0[u][i], f3[u][i]);
    }
}

void enter()
{
    int n, k;
    cin >> n >> k;
    const int& d = 254;
    memset (f2, d, sizeof (f2));
    memset (f1, d, sizeof (f1));
    memset (f4, d, sizeof (f4));
    memset (f0, d, sizeof (f0));
    memset (f3, d, sizeof (f3));
    vector<int> v;
    for (int i = 1; i <= n; ++ i)
    cin >> w[i];
    for (int i = 1; i < n; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    Dfs (1, 0);
    cout << max (f0[1][k], f1[1][k]);
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