#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "WIFI"

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

struct edge
{
	long long x, y, cap, flow, cost;
};

struct MinCost
{
	int n, s, t, sol1 = 0, sol2 = 0;

	struct Z
	{
		int v, c, w;
		Z (){}
		Z (int V, int C, int W)
		{
			v = V; c = C; w = W;
		}
	};

	vector<Z> g;
	vector<vector<int> > e;
	vector<pair<int, int> > tr ;

	MinCost (int N, int S, int T)
	{
		n = N; s = S; t = T;
		e.resize(n + 2);
		tr.resize(n + 2);
	} 

	void AddEdge (int u, int v, int c, int w)
	{
		g.emplace_back(v, c, w);
		e[u].emplace_back(g.size() - 1);
		g.emplace_back(u, 0, - w);
		e[v].emplace_back(g.size() - 1);
	}

	bool dijkstra ()
	{
		vector<int> d (n + 2, - 1);
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> qu;
		qu.emplace(0, s);
		d[s] = 0;
		while (qu.size())
		{
			int u = qu.top().second, w = qu.top().first;
			qu.pop();
			if (d[u] != w) continue;
			if (u == t) break;
			for (const int&i : e[u])
			if (g[i].c)
			{
				int v = g[i].v;
				if (d[v] != - 1 && d[v] <= w + g[i].w) continue;
				d[v] = w + g[i].w;
				qu.emplace(d[v], v);
				tr[v] = {u, i};
			}
		}
		return (d[t] != - 1);
	}

	void TracePath ()
	{
		int u = t, mi = INT_MAX;
		while (1)
		{	
			if (u == s) break;
			mi = min (mi, g[tr[u].second].c);
			u = tr[u].first;
		}
		u = t;
		sol1 += mi;
		while (1)
		{
			if (u == s) break;
			g[tr[u].second].c -= mi;
			g[tr[u].second ^ 1].c += mi;
			sol2 += mi * g[tr[u].second].w;
			u = tr[u].first;
		}
	}

	void process ()
	{
		while (dijkstra()) 
		TracePath();
	}

};

int x[210], y[210];
int dis (int x, int X, int y, int Y)
{
    return (X - x) * (X - x) + (Y - y) * (Y - y);
}

void enter()
{
    int m, n;
    cin >> m >> n;
    MinCost sol (n + m + 4, n + m + 1, n + m + 4);
    int k = n / m;
    int r = n % m;
    for (int i = 1; i <= m; ++ i)
    {
        cin >> x[i] >> y[i];
        sol.AddEdge (i, n + m + 2, k, 0);
        sol.AddEdge (i, n + m + 3, 1, 0);
    }
    sol.AddEdge (n + m + 2, n + m + 4, n - r, 0);
    sol.AddEdge (n + m + 3, n + m + 4, r, 0);
    for (int i = 1; i <= n; ++ i)
    {
        int X, Y;
        cin >> X >> Y;
        sol.AddEdge (n + m + 1, m + i, 1, 0);
        for (int j = 1; j <= m; ++ j)
        sol.AddEdge (m + i, j, 1, dis (x[j], X, y[j], Y));
    }
	sol.process();
    cout << sol.sol2 << "\n";
    vector<int> Sol (n + 3);
	for (int u = 1; u <= n; ++ u)
	for (const int& i : sol.e[u + m])
	if (!sol.g[i].c)
	Sol[u] = sol.g[i].v;
    for (int i = 1; i <= n; ++ i)
    cout << Sol[i] << " ";
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