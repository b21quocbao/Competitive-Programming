#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int x[210];
int a[210];
int f[210][2];
bool ok[210];
vector<int> e[210];

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

int F (int u, int d, int w)
{
    if (f[u][d] != - 1) return f[u][d];
    if (!ok[u] && d) return 0;
    if (d) f[u][d] = a[u]; else f[u][d] = 0;
    for (int v : e[u])
    if (v != w)
    {
        if (d)
        f[u][d] += F (v, 0, u);
        else
        f[u][d] += max (F (v, 1, u), F (v, 0, u));
    }
    return f[u][d];
}

void enter()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    e[i].clear();
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int q, t;
    cin >> q;
    for (int l = 0; l < q; ++ l)
    {
        cin >> t;
        for (int j = 0; j < t; ++ j)
        {
            cin >> x[j];
            ok[x[j]] = 1;
        }
        memset (f, - 1, sizeof (f));
        // cerr << F (1, 0, 0);
        cout << max (F (1, 0, 0), F (1, 1, 0)) << "\n";
        for (int j = 0; j < t; ++ j)
        ok[x[j]] = 0;
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}