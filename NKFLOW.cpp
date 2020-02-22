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

struct Flow
{
    int n, s, t;
    vector<vector<int> > e; 
    vector<pair<int, int> > g;
    vector<int> h, ex;
    vector<vector<int> ::iterator> cur;
    queue<int> qu;

    Flow (){}

    Flow (const int& N, const int& S, const int& T)
    {
        n = N; s = S; t = T;
        e.resize(n + 2);
        h.resize(n + 2);
        ex.resize(n + 2);
        cur.resize(n + 2);
    }

    void AddEdge (const int& u, const int& v, const int& c)
    {
        e[u].emplace_back (g.size());
        g.emplace_back(v, c);
        e[v].emplace_back (g.size());
        g.emplace_back(u, 0);
    }

    void Bfs (const int& s)
    {
        queue<int> qu;
        qu.emplace(s);
        while (qu.size())
        {
            int u = qu.front();
            qu.pop();
            for (const int& v : e[u])
            if (h[g[v].first] == 2 * n - 1 && g[v ^ 1].second)
            {
                h[g[v].first] = h[u] + 1;
                qu.emplace(g[v].first);
            }
        }
    }

    void Relabel()
    {
        fill (h.begin(), h.end(), 2 * n - 1);
        h[s] = n; h[t] = 0;
        Bfs (t);
        Bfs (s);
        for (int i = 1; i <= n; ++ i)
        cur[i] = e[i].begin();
    }

    bool Excess (const int& u) 
    {
        return (u != s && u != t && !ex[u]);
    }

    void Push (const int& u, const int& v)
    {
        int mi = min (ex[u], g[v].second);
        if (!mi) return;
        if (Excess (g[v].first)) qu.emplace(g[v].first);
        ex[u] -= mi;
        ex[g[v].first] += mi;
        g[v].second -= mi;
        g[v ^ 1].second += mi;
    }
    
    void Init ()
    {
        Relabel();
        ex[s] = INT_MAX;
        for (auto& v : e[s])
        Push (s, v);
    }

    void Lift (const int& u)
    {
        int mi = INT_MAX;
        for (const int& v : e[u])
        if (g[v].second)
        mi = min (mi, h[g[v].first]);
        h[u] = mi + 1;
    }

    void Process ()
    {
        int cn = 0;
        while (qu.size())
        {
            int u = qu.front(); qu.pop();
            for (; (cur[u] != e[u].end() && ex[u]); ++ cur[u])
            if (h[u] > h[g[*cur[u]].first])
            Push (u, *cur[u]);
            if (ex[u])
            {
                if (++ cn == n)
                {
                    cn = 0;
                    Relabel();
                }
                else
                {
                    Lift (u);
                    cur[u] = e[u].begin();
                }
                qu.emplace (u);
            }
        }
    }
    
    int Sol()
    {
        Init();
        Process();
        return ex[t];
    }
};

void enter()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Flow sol (n, s, t);
    for (int i = 0; i < m; ++ i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        sol.AddEdge(u, v, c);
    }
    cout << sol.Sol();
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