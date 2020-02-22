#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TOUR"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 2 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int cn;
int u[mn], v[mn], w[mn], U[mn], V[mn], W[mn], h[mm];
int ok[mm];
bool inq[mm];

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

template <class T>
class Dijkstra
{
    #define ii pair<T, int>
    public:
        int n;
        vector<int> tr;
        vector<T> d;
        vector<vector<ii> > e;
        priority_queue<ii, vector<ii>, greater<ii> > qu;
        void AddEdge (int u, int v, T c, bool Directed = 0)
        {
            e[u].emplace_back(c, v);
            if (!Directed)
            e[v].emplace_back(c, u);
        }
        
        void Init (int u)
        {
            while (qu.size()) qu.pop();
            qu.emplace (0, u);
            fill (d.begin(), d.end(), - 1);
            fill (tr.begin(), tr.end(), 0);
            d[u] = 0;
        }
        void process (int u)
        {
            while (qu.size())
            {
                int x = qu.top().first, u = qu.top().second;
                qu.pop();
                if (x != d[u]) continue;
                for (auto v : e[u])
                if (d[v.second] == - 1 || d[v.second] > d[u] + v.first)
                {
                    tr[v.second] = u;
                    d[v.second] = d[u] + v.first;
                    qu.emplace (d[v.second], v.second);
                }
            }
        }

        Dijkstra (int N, bool Ok = 0) : n (N)
        {
            tr.resize (n + 2);
            d.resize (n + 2);
            e.resize(n + 2);
        }

        void Sol(int u)
        {
            Init(u);
            process(u);
        }

        vector<int> Trace (int u, int v)
        {
            Init(u);
            process(u, v);  
            vector<int> V;
            while (v)
            {
                V.emplace_back(v);
                v = tr[v];
            }
            reverse (V.begin(), V.end());
            return V;
        }  
};

template <class T>
class Dijkstra2
{
    #define ii pair<T, int>
    public:
        int n;
        vector<int> tr;
        vector<T> d, cn;
        vector<vector<ii> > e;
        priority_queue<ii, vector<ii>, less<ii> > qu;
        void AddEdge (int u, int v, T c, bool Directed = 0)
        {
            e[u].emplace_back(c, v);
            ++ cn[v];
            if (!Directed)
            e[v].emplace_back(c, u);
        }
        
        void Init (int u)
        {
            while (qu.size()) qu.pop();
            qu.emplace (0, u);
            fill (d.begin(), d.end(), - 1);
            fill (tr.begin(), tr.end(), 2);
            d[u] = 0;
        }
        void process (int u)
        {
            d[u] = 0;
            tr[u] = 1;
            vector<int> qu;
            v.emplace_back(u);
            while (qu.size())
            {
            }
        }

        Dijkstra2(){}

        Dijkstra2 (int N) : n (N)
        {
            tr.resize (n + 2);
            d.resize (n + 2);
            e.resize(n + 2);
        }

        void resize (int N)
        {
            n = N;
            tr.resize (n + 2);
            d.resize (n + 2);
            e.resize(n + 2);
            cn.resize(n + 2);
        }

        void Sol(int u)
        {
            Init(u);
            process(u);
        }

        vector<int> Trace (int u, int v)
        {
            Init(u);
            process(u, v);  
            vector<int> V;
            while (v)
            {
                V.emplace_back(v);
                v = tr[v];
            }
            reverse (V.begin(), V.end());
            return V;
        }  
};

Dijkstra2<int> sol3;

void dfs (int u)
{
    if (ok[u]) return;
    inq[u] = 1; ok[u] = 1;
    for (int v : e[u])
    {
        if (inq[v])
        {
            cout << - 1;
            exit (0);
        }
        dfs (v);
    }
    inq[u] = 0;
}

void enter()
{
    // cout << - 1;
    // return;
    int n, s, t, m;
    read (n); read (s); read (t);
    read (m);
    Dijkstra<int> sol (n), Sol (n);
    for (int i = 0; i < m; ++ i)
    {
        read (u[i]); read (v[i]); read (w[i]);
        sol.AddEdge (u[i], v[i], w[i]);
    }
    int M;
    read (M);
    for (int i = 0; i < M; ++ i)
    {
        read (U[i]); read (V[i]); read (W[i]);
        Sol.AddEdge (U[i], V[i], W[i]);
    }
    sol.Sol(t);
    Sol.Sol(t);
    sol3.resize(2 * n);
    for (int i = 0; i < m; ++ i)
    {
        if (sol.d[u[i]] > sol.d[v[i]])
        sol3.AddEdge (u[i], v[i] + n, w[i], 1);
        if (sol.d[v[i]] > sol.d[u[i]])
        sol3.AddEdge (v[i], u[i] + n, w[i], 1);
    }
    for (int i = 0; i < M; ++ i)
    {
        if (Sol.d[U[i]] > Sol.d[V[i]])
        sol3.AddEdge (U[i] + n, V[i], W[i], 1);
        if (Sol.d[V[i]] > Sol.d[U[i]])
        sol3.AddEdge (V[i] + n, U[i], W[i], 1);
    }
    dfs (s, 0);
    sol3.Sol (s);
    cout << max (sol3.d[t], sol3.d[t + n]);

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