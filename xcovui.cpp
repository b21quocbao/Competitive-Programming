/*
Code by b21
Time: 10:55 Sun 01/12/2019
*/

#include <bits/stdc++.h>

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("xcovui.inp"))
    {
        freopen("xcovui.inp", "r", stdin);
        freopen("xcovui.out", "w", stdout);
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


std::vector<int> findLowestEmissionRoute(int inN, int inSrc, int inDest, std::vector<std::vector<int>> matrixMap)
{
    Dijkstra<int> D (inN);
    for (int i = 1; i <= inN; ++ i)
    for (int j = 1; j <= inN; ++ j)
    D.AddEdge(i, j, matrixMap[i - 1][j - 1]);
    return D.Trace(inSrc, inDest);
}


void enter()
{
    
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