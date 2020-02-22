#include <bits/stdc++.h>

#define fn "test"
#define fn1 "RESCUE"

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


class BFS
{
    public:
    vector<vector<int> > e;
    vector<int> d;
    vector<vector<int> > trace;
    int n;
    vector<int> V;
    vector<vector<int> > SolV; 
    int s;
    BFS (int N) : n (N)
    {
        e.resize(n + 2);
        d.resize(n + 2, - 1);
        trace.resize(n + 2);
    }

    void AddEdge (int u, int v, bool Directed = 0)
    {
        e[u].emplace_back(v);
        if (!Directed)
        e[v].emplace_back(u);
    }

    int process (int u = 1)
    {
        s = u;
        queue<int> qu;
        qu.emplace(u);
        d[u] = 0;
        while (qu.size())
        {
            int u = qu.front(); 
            qu.pop();
            for (int v : e[u])
            if (d[v] == - 1)
            {
                d[v] = d[u] + 1;
                trace[v].emplace_back(u);
                qu.push (v);
            }
            else if (d[v] == d[u] + 1)
            trace[v].emplace_back(u);                
        }
    }

    int ShortestPath(int v)
    {
        return d[v];
    }

    void DFS (int u)
    {
        V.emplace_back(u);        
        if (u == s)
        {
            reverse (V.begin(), V.end());
            SolV.emplace_back(V);
            reverse (V.begin(), V.end());
            V.pop_back();
            return;
        }
        for (int v : trace[u])
        {
            DFS (v);
        }
        V.pop_back();
    }

    vector<vector<int> > Trace (int v)
    {
        V.clear();
        SolV.clear();
        DFS (v);
        return SolV;
    }
};

void enter()
{
    int m, n, s;
    cin >> n >> m >> s;
    BFS sol(n);
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        sol.AddEdge (u, v);
    }
    int q;
    cin >> q;
    sol.process(s);
    for (int i = 0; i < q; ++ i)
    {
        int v, k;
        cin >> v >> k;
        vector<vector<int> >  V = sol.Trace(v);
        vector<int> r;
        for (auto v : V)
        if (k < v.size())
        r.emplace_back(v[k]);
        sort (r.begin(), r.end());
        r.resize(unique (r.begin(), r.end()) - r.begin());
        if (r.empty())
        {
            cout << 0;
        }
        else if (r.size() == 1)
        {
            cout << r.back();
        }
        else cout << - 1;
        cout << "\n";
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}