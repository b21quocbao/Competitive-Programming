#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "DANANG"

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


struct Z
{
    int u, c, i;
    Z (){}
    Z (int U, int C, int I)
    {
        u = U; c = C; i = I;
    }
    bool operator < (const Z& a) const
    {
        return c > a.c;
    }
};

struct Z1
{
    int w, u, i;
    Z1 (){}
    Z1 (int W, int U, int I)
    {
        w = W; u = U; i = I;
    }
    bool operator < (const Z1& a) const
    {
        return w < a.w;
    }
};

vector<pair<int, int> > e[mn];
vector<int> d[mn];

void enter()
{
    int n, m, D;
    cin >> n >> m >> D;
    e[0].emplace_back (-D, 1);
    for (int i = 0; i < m; ++ i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        e[u].emplace_back(c, v);
        e[v].emplace_back(c, u);
    }
    for (int i = 0; i <= n; ++ i)
    d[i].resize (e[i].size(), - 1);
    priority_queue<Z> qu;
    qu.emplace (0, 0, 0);
    d[0][0] = 0;
    int cn = 0;
    while (qu.size())
    {
        int u = qu.top().u, c = qu.top().c, i = qu.top().i, w = e[u][i].first, v = e[u][i].second;
        qu.pop();
        if (d[u][i] != c) continue;
        if (v == n)
        {
            cout << c << "\n";
            return;
        }
        for (int i = 0; i < e[v].size(); ++ i)
        {
            if (d[v][i] != - 1 && d[v][i] <= c + e[v][i].first) continue;
            if (e[v][i].first < w + D) continue;
            d[v][i] = c + e[v][i].first;
            qu.emplace (v, d[v][i], i);
        }
    }
    cout << - 1;
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
