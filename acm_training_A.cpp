/*
Code by b21
Time: 15:03 Mon 24/02/2020
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
   else if (ifstream("acm_training_A.inp"))
    {
        freopen("acm_training_A.inp", "r", stdin);
        freopen("acm_training_A.out", "w", stdout);
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

int b;

template <class T>
class Dijkstra
{
    public:
    struct ii {
        int v, c, w;
        ii () {}
        ii (int C, int W, int V) {
            c = C; w = W; v = V;
        }
        bool operator < (const ii& a) const {
            return c < a.c;
        }
        bool operator > (const ii& a) const {
            return c > a.c;
        }
    };
    public:
        int n;
        vector<map<int, int, greater<int>> > d;
        vector<vector<ii> > e;
        priority_queue<ii, vector<ii>, greater<ii> > qu;
        void AddEdge (int u, int v, T c, T w, bool Directed = 0)
        {
            if (w > b) return;
            e[u].emplace_back(c, w, v);
            if (!Directed)
            e[v].emplace_back(c, w, u);
        }
        
        void Init (int u)
        {
            qu.emplace (0, 0, u);
            d[u][0] = 0;
        }
        int process (int u, int v)
        {
            while (qu.size())
            {
                int c = qu.top().c, u = qu.top().v, w = qu.top().w;
                qu.pop();
                if (c != d[u][w]) continue;
                if (u == v) return c;
                for (auto v : e[u])
                if (w + v.w <= b && (d[v.v].lower_bound(w + v.w) == d[v.v].end() || d[v.v].lower_bound(w + v.w)->second > c + v.c))
                {
                    d[v.v][w + v.w] = c + v.c;
                    qu.emplace (c + v.c, w + v.w, v.v);
                }
            }
            return - 1;
        }

        Dijkstra (int N) : n (N)
        {
            d.resize (n + 2);
            e.resize(n + 2);
        }

        int Sol(int u, int v)
        {
            Init(u);
            return process(u, v);
        }
};

vector<pair<int, int> > v[1010];
int x[1010], y[1010];
int c[110];

int D (int xs, int ys, int xd, int yd) {
    return (int)(ceil(sqrt(pow(xs - xd, 2) + pow(ys - yd, 2))));
}

void enter()
{
    int xs, ys, xd, yd;
    cin >> xs >> ys;
    cin >> xd >> yd;
    cin >> b;
    cin >> c[0];
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++ i)
    cin >> c[i];
    int n;
    cin >> n;
    Dijkstra<int> sol(n + 2);
    sol.AddEdge(n, n + 1, D(xs, ys, xd, yd) * c[0], D (xs, ys, xd, yd));
    for (int i = 0; i < n; ++ i)
    {
        int l;
        cin >> x[i] >> y[i] >> l;
        sol.AddEdge (n, i, D(xs, ys, x[i], y[i]) * c[0], D (xs, ys, x[i], y[i]));
        sol.AddEdge (n + 1, i, D(xd, yd, x[i], y[i]) * c[0], D (xd, yd, x[i], y[i]));
        for (int j = 0; j < l; ++ j) {
            int V, m;
            cin >> V >> m;
            v[i].emplace_back(V, m);
        }
    }
    for (int i = 0; i < n; ++ i)
    for (auto j : v[i])
    sol.AddEdge(i, j.first, D(x[i], y[i], x[j.first], y[j.first]) * c[j.second], D(x[i], y[i], x[j.first], y[j.first]));
    cout << sol.Sol(n, n + 1);
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