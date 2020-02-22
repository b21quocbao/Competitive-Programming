#include <bits/stdc++.h>

#define fn "test"
#define fn1 "CONSTRUC"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<int> e[mm], g[mm];
int k[mm], cn[mm], w[mm], f[mm];
int l[mm];
bool ok[mm];

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
        void process (int u, int v)
        {
            while (qu.size())
            {
                int x = qu.top().first, u = qu.top().second;
                qu.pop();
                if (x != d[u]) continue;
                if (u == v) return;
                for (auto v : e[u])
                if (d[v.second] == - 1 || d[v.second] > d[u] + v.first)
                {
                    tr[v.second] = u;
                    d[v.second] = d[u] + v.first;
                    qu.emplace (d[v.second], v.second);
                }
            }
        }

        Dijkstra (int N) : n (N)
        {
            tr.resize (n + 2);
            d.resize (n + 2);
            e.resize(n + 2);
        }

        int Sol(int u, int v)
        {
            Init(u);
            process(u, v);
            return d[v];
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

void dfs (int u)
{
    if (ok[u]) 
    return;
    ok[u] = 1;
    for (int v : g[u])
    dfs (v);
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> k[i];
        e[0].emplace_back(i);
        g[i].emplace_back(0);
        for (int j = 1; j <= k[i]; ++ j)
        {
            int u;
            cin >> u;
            e[u].emplace_back(i);   
            g[i].emplace_back(u);
        }
        ++ k[i];
        cin >> w[i];
    }   
    queue<int> qu;
    int sol = 0;
    qu.emplace(0);
    while (qu.size())
    {
        int u = qu.front();
        sol = max (sol, f[u] + w[u]);
        qu.pop();
        for (int v : e[u])
        {
            f[v] = max (f[v], f[u] + w[u]);
            if (++ cn[v] == k[v]) qu.emplace(v);
        }
    }
    while (qu.size()) qu.pop();
    memset (cn, 0, sizeof (cn));
    memset (l, 1, sizeof (l));
    for (int i = 1; i <= n; ++ i)
    for (int j : g[i])
    dfs (j);
    for (int i = 1; i <= n; ++ i)
    if (!ok[i])
    {
        qu.emplace(i);
        l[i] = sol;
    }
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();
        l[u] -= w[u];
        for (int v : g[u])
        {
            l[v] = min (l[v], l[u]);
            if (++ cn[v] == e[v].size()) qu.emplace(v);
        }
    }
    cout << sol << "\n";
    for (int i = 1; i <= n; ++ i)
    cout << f[i] << " " << l[i] << "\n";
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