#include <bits/stdc++.h>

#define fn "test"
#define fn1 "STUNN"

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

class BridgeAcc 
{
    public:

    int Bridge = 0, Node = 0, cn = 0, n;
    vector<int> low, num, sc;
    vector<long long > sol;
    vector<vector<int> > e;

    void AddEdge (int u, int v)
    {
        e[u].emplace_back (v);
        e[v].emplace_back (u);
    }

    void dfs (int u, int w)
    {
        num[u] = low[u] = ++ cn;
        int nc = 0;
        sc[u] = 0;
        bool Ok = 0;
        vector<int> l;
        long long res = 0;
        long long tg = 0;
        for (int v : e[u])
        if (v != w)
        {
            if (!num[v]) 
            {
                ++ nc;
                dfs (v, u);
                sc[u] += sc[v];
                low[u] = min (low[u], low[v]);
                if (low[v] < num[u])
                tg += sc[v];
                else
                l.emplace_back (sc[v]);
            }
            else low[u] = min (low[u], num[v]);
        }
        tg += (n - sc[u] - 1);
        ++ sc[u];
        for (int i : l)
        {
            res += 1ll * tg * i;
            tg += i;
        }
        if (!w) 
        {
            if (nc >= 2) Ok = 1;
            else Ok = 0;
        }
        sol[u] = n - 1;
        sol[u] += res;
    }

    BridgeAcc (int N) : n (N)
    {
        e.resize(n + 2);
        sc.resize(n + 2);
        low.resize(n + 2);
        num.resize(n + 2);
        sol.resize(n + 2);
    }

    void process ()
    {
        dfs (1, 0);
        for (int i = 1; i <= n; ++ i)
        cout << 2ll * sol[i] << "\n";
    }
};

void enter()
{
    int n, m;
    read (n); read (m);
    BridgeAcc sol (n);
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        sol.AddEdge (u, v);
    }
    sol.process();
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}