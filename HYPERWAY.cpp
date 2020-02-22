#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "HYPERWAY"

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

struct Z
{
    int u, c, w;
    Z (){}
    Z (int U, int C, int W)
    {
        u = U; c = C; w = W;
    }
    bool operator < (const Z& a) const
    {
        return c < a.c;
    }
};

vector<pair<int, int> > e[mn];

void enter()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++ i)
    {
        int x, y, d = 0;
        string s;
        cin >> x >> y >> s;
        if (s[0] == 'x')
        e[x].emplace_back(y, - 1);
        else
        {
            for (char c : s)
            d = d * 10 + c - '0';
            e[x].emplace_back(y, d);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++ i)
    {
        int u, v;
        cin >> u >> v;
        map<int, int, greater<int> > d[n + 2];
        priority_queue<Z> qu;
        qu.emplace(u, 0, 0);
        while (qu.size())
        {
            int u = qu.top().u, c = qu.top().c, w = qu.top().w;
            qu.pop();
            for (auto v : e[u])
            {
                int V = v.first, C = c + (v.second == - 1 ? 1 : 0), W = w + (v.second == - 1 ? 0 : v.second);
                auto it = d[V].lower_bound (C);
                if ((it != d[V].end()) && (it -> second <= W)) continue;
                d[V][C] = W;
                qu.emplace(V, C, W);
            }
        }
        if (d[v].empty())
        {
            cout << 0 << " " << 0 << "\n";
            continue;
        }
        if (!d[v].count (0))
        {
            cout << "inf\n";
            continue;   
        }
        int sol = 0, X;
        for (int x = 1;; ++ x)
        {
            int mi = INT_MAX;
            for (auto y : d[v])
            mi = min (mi, y.first * x + y.second);
            X = x;
            if (mi >= d[v][0]) break;
            sol += mi;
        }
        sol += d[v][0];
        cout << X << " " << sol << "\n";
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