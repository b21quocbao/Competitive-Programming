#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 9 * (int)(1e3) + 10;
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

int f[mm][mm];
int ok[mm];
int n, m, k;
vector<int> e[mm];

int F (int N, int K)
{
    if (ok[K] && ok[K] != N) return 0;
    if (K == k) return 1;
    if (f[N][K] != - 1) return f[N][K]; 
    f[N][K] = 0;
    for (const int& v : e[N])
    {
        f[N][K] += F (v, K + 1);
        if (f[N][K] >= mod) f[N][K] -= mod; 
    }
    return f[N][K];
}

void enter()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
    {
        e[i].clear();
        e[i].emplace_back(i);
    }
    for (int i = 0; i <= k; ++ i)
    ok[i] = 0;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int q;
    cin >> q;
    bool Ok = 0;
    for (int i = 0; i < q; ++ i)
    {
        int x, y;
        cin >> x >> y;
        if (ok[y]) Ok = 1;
        ok[y] = x;
    }
    if (Ok)
    {
        cout << 0 << "\n";
        return;
    }
    for (int j = k; j >= 0; -- j)
    for (int i = 1; i <= n; ++ i)
    if (!ok[j] || ok[j] == i)
    {
        f[i][j] = 0;
        if (j == k)
        {
            f[i][j] = 1;
            continue;
        }
        for (const int& v : e[i])
        {
            f[i][j] += f[v][j + 1];
            if (f[i][j] >= mod) f[i][j] -= mod;
        }
    }
    else f[i][j] = 0;
    cout << f[1][0] << "\n";
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