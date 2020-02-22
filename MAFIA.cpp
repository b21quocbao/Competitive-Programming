#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MAFIA"

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

class MaxFlow
{
    public:
    
    int n, m, s, t;
    queue<int> qu;
    vector<int> cn, h, ex;
    struct Z
    {
        int v,  f,  c,  t;
        Z () {}
        Z (int V, int F, int C, int T) : v (V), f (F), c (C), t (T) {}
    };
    vector<vector<Z>::iterator > cur; 
    vector<vector<Z>> e;
    void AddE (int u, int v, int c, bool ok = 0)
    {
        e[u].emplace_back(v, 0, c, e[v].size());
        if (!ok)
        e[v].emplace_back(u, 0, 0, e[u].size() - 1);
        else
        e[v].emplace_back(u, 0, c, e[u].size() - 1);
    }
    MaxFlow (int N, int M, int S, int T) : 
    n (N), m (M), s (S), t (T) 
    {
        cn.resize (2 * n + 2);
        h.resize(n + 2, 1);
        ex.resize(n + 2);
        cur.resize(n + 2);
        e.resize(n + 2);
    }

    void Argue (int u, Z& v, int c)
    {
        ex[u] -= c;
        ex[v.v] += c;
        v.f += c;
        e[v.v][v.t].f -= c;
    }

    void Init()
    {
        for (auto& u : e[s])
        {
            Argue (s, u, u.c);
            if (u.v != t)
            qu.emplace (u.v);
        }
        for (int i = 1; i <= n; ++ i)
        cur[i] = e[i].begin();
        h[s] = n;
        h[t] = 0;
        cn[1] = n - 2;
        cn[n] = cn[0] = 1;
    }

    void UdH (int u, int H)
    {
        -- cn[h[u]];
        h[u] = H;
        ++ cn[H];
    }

    void Gap (int H)
    {
        if (H <= 0 || H >= n || cn[H]) return;
        for (int u = 1; u <= n; ++ u)
        if (h[u] > H && h[u] <= n && u != s)
        {
            UdH (u, n + 1);
            cur[u] = e[u].begin();
        }
    }

    void Lift (int u)
    {
        int minH = 2 * n;
        for (auto v : e[u])
        if (v.c > v.f)
        minH = min (minH, h[v.v] + 1);
        int r = h[u];
        UdH (u, minH);
        Gap (r);
    }

    void Push (int u, vector<Z>::iterator r)
    {
        int mi = min (r->c - r->f, ex[u]);
        Argue (u, *r, mi);
    }

    void process ()
    {
        while (qu.size())
        {
            int u = qu.front(); qu.pop();
            for (; cur[u] != e[u].end(); ++ cur[u])
            {
                auto r = cur[u];
                if (r->f == r->c) continue;
                if (h[u] <= h[r->v]) continue;
                if (!ex[r->v] && r->v != s && r->v != t) qu.emplace (r->v);
                Push (u, r);
                if (!ex[u]) break;
            }
            if (ex[u])
            {
                Lift (u);
                cur[u] = e[u].begin();
                qu.push (u);
            }
        }
    }

    int Sol ()
    {
        Init();
        process();
        return ex[t];
    }

};

void enter()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    MaxFlow Sol (n * 2, m, s, t);
    for (int i = 1; i <= n; ++ i)
    {
        int c;
        cin >> c;
        Sol.AddE (i, n + i, c);
    }
    for (int i = 1; i <= m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        Sol.AddE (u + n, v, mod);
        Sol.AddE (v + n, u, mod);
    }
    Sol.Sol();
    for (int u = 1; u <= n; ++ u)
    for (auto v : Sol.e[u])
    if (v.v == u + n)
    if (v.f == v.c)
    cout << u << " ";
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