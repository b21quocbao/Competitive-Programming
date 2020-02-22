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

struct Match
{
    vector<vector<int> > c; 
    vector<int> fx, fy, tr, arg, matchX, matchY, d;
    int n, t, s;
    queue<int> qu;

    Match (int N)
    {
        n = N;
        c.resize(n + 2, vector<int> (n + 2, base));
        fx.resize(n + 2, base);
        fy.resize(n + 2, base);
        tr.resize(n + 2);
        arg.resize(n + 2);
        matchX.resize(n + 2);
        matchY.resize(n + 2);
        d.resize(n + 2);
    }

    void AddEdge (int u, int v, int w)
    {
        c[u][v] = w;
    }

    void Init()
    {
        for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
        fx[i] = min (fx[i], c[i][j]);
        for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
        fy[j] = min (fy[j], c[i][j] - fx[i]);
    }

    inline int Get (int u, int v)
    {
        return c[u][v] - fx[u] - fy[v];
    }

    void InitBfs ()
    {
        while (qu.size()) qu.pop();
        t = 0;
        qu.emplace(s);
        for (int i = 1; i <= n; ++ i)
        {
            tr[i] = 0;
            d[i] = Get (s, i);
            arg[i] = s;
        }
    }

    void Argument()
    {
        int mi = INT_MAX;
        for (int i = 1; i <= n; ++ i)
        if (!tr[i])
        mi = min (mi, d[i]);
        fx[s] += mi;
        for (int i = 1; i <= n; ++ i)
        if (tr[i])
        {
            fy[i] -= mi;
            fx[matchY[i]] += mi;
        }
        else d[i] -= mi;
        for (int i = 1; i <= n; ++ i)
        if (!tr[i] && !d[i])
        {
            tr[i] = arg[i];
            if (!matchY[i])
            {
                t = i;
                return;
            }
            qu.emplace(matchY[i]);
        }
    }

    void Bfs ()
    {
        while (qu.size())
        {
            int u = qu.front(); qu.pop();
            for (int v = 1; v <= n; ++ v)
            if (!tr[v])
            {
                int C = Get (u, v);
                if (!C)
                {
                    tr[v] = u;
                    if (!matchY[v])
                    {
                        t = v;
                        return;
                    }
                    qu.emplace (matchY[v]);
                }
                else if (d[v] > C)
                {
                    d[v] = C;
                    arg[v] = u;
                }
            }
        }
    }

    void TracePath()
    {
        while (1)
        {
            matchY[t] = tr[t];
            swap (t, matchX[tr[t]]);
            if (!t) break;
        }
    }

    void Sol()
    {
        Init();
        for (s = 1; s <= n; ++ s)
        {
            InitBfs();
            while (!t)
            {
                Bfs ();
                if (!t) Argument();
            }
            TracePath();
        }
    }

    void PrintPath()
    {
        Sol();
        int sol = 0, sol1 = 0;
        for (int i = 1; i <= n; ++ i)
        if (c[i][matchX[i]] != base)
        {
            sol += c[i][matchX[i]];
            ++ sol1;
        }
        cout << sol << "\n";
        cout << sol1 << "\n";
        for (int i = 1; i <= n; ++ i)
        if (c[i][matchX[i]] != base)
        cout << i << " " << matchX[i] << "\n";
    }
};

void enter()
{
    int n;
    cin >> n;
    Match sol (n);
    int u, v, c;
    while (cin >> u >> v >> c)
    sol.AddEdge (u, v, c);
    sol.PrintPath();
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