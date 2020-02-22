#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ASSIGN"

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
bool read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    int cn = 0;
    while (!isdigit(ch)) 
    {
        f = ch == '-' ? - f : f, ch = getchar();
        if (++ cn == 5) return 0;
    }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
    return 1;
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

class Matching
{
    public:
    int n, m, Time = 0, sol = 0;
    vector<int> match, match1, V, h, ok;
    vector<vector<int> > e;
    Matching (int N, int M) : n (N), m (M) 
    {
        e.resize(n + 2);
        match.resize(m + 2);
        match1.resize(n + 2);
        V.reserve (n + 2);
        for (int i = 1; i <= n; ++ i)
        V.emplace_back(i);
        h.resize(m + 2);
        ok.resize(n + 2);
    }

    void AddEdge (int u, int v)
    {
        e[u].emplace_back(v);
    }

    bool Bfs ()
    {
        queue<int> qu;
        fill(h.begin(), h.end(), 0);
        for (int u : V)
        for (int v : e[u])
        if (!h[v])
        {
            h[v] = 1;
            qu.push (v);
        }
        bool ok = 0;
        while (qu.size())
        {
            int u = qu.front(); qu.pop();
            if (!match[u])
            {
                ok = 1;
                continue;
            }
            for (int v : e[match[u]])
            if (!h[v])
            {
                h[v] = h[u] + 1;
                qu.push (v);
            }
        }
        return ok;
    }

    bool Dfs (int u, int H)
    {
        if (ok[u] == Time) return 0;
        ok[u] = Time;
        for (int v : e[u])
        if (h[v] == H)
        {
            if (!match[v] || Dfs (match[v], H + 1)) 
            {
                match[v] = u;
                match1[u] = v;
                return 1;
            }
        }
        return 0;
    }

    void process ()
    {
        while (Bfs())
        {
            ++ Time;
            for (int i = V.size() - 1; i >= 0; -- i)
            if (Dfs (V[i], 1))
            {
                ++ sol;
                V[i] = V.back();
                V.pop_back();
            }
        }
    }

    int Sol()
    {
        process();
        return sol;
    }
};

void enter()
{
    int n, m, u, v;
    read (n); read (m);
    Matching sol (n, m);
    while (read (u))
    {
        read (v);
        sol.AddEdge (u, v);
    }
    sol.process();
    cout << sol.sol << "\n";
    for (int i = 1; i <= m; ++ i)
    cout << sol.match[i] << " ";
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