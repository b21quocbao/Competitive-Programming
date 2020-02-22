#include<bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

struct edge
{
	long long x, y, cap, flow, cost;
};

struct MinCostMaxFlow
{
	long long n, S, T;
	vector < vector <long long> > a;
	vector <long long> dist, prev, done, pot;
	vector <edge> e;
	
	MinCostMaxFlow() {}
	MinCostMaxFlow(long long _n, long long _S, long long _T)
	{
		n = _n; S = _S; T = _T;
		a = vector < vector <long long> >(n + 1);
		dist = vector <long long>(n + 1);
		prev = vector <long long>(n + 1);
		done = vector <long long>(n + 1);
		pot = vector <long long>(n + 1, 0);
	}
	
	void addEdge(long long x, long long y, long long _cap, long long _cost)
	{
		edge e1 = {x, y, _cap, 0, _cost};
		edge e2 = {y, x, 0, 0, -_cost};
		a[x].push_back(e.size()); e.push_back(e1);
		a[y].push_back(e.size()); e.push_back(e2);
	}
	
	pair <long long,long long> dijkstra()
	{
		long long flow = 0, cost = 0;
		for (long long i = 1; i <= n; i++) done[i] = 0, dist[i] = oo;
		priority_queue < pair<long long,long long> > q;
		dist[S] = 0; prev[S] = -1;
		q.push(make_pair(0, S));
		while (!q.empty())
		{
			long long x = q.top().second; q.pop();  
			if (done[x]) continue;
			done[x] = 1;
			for (int i = 0; i < int(a[x].size()); i++)
			{
				long long id = a[x][i], y = e[id].y;
				if (e[id].flow < e[id].cap)
				{
					long long D = dist[x] + e[id].cost + pot[x] - pot[y];
					if (!done[y] && D < dist[y])
					{
						dist[y] = D; prev[y] = id;
						q.push(make_pair(-dist[y], y));
					}
				}
			}
		}
		
		// for (long long i = 1; i <= n; i++) pot[i] += dist[i];
		
		if (done[T])
		{
			flow = oo;
			for (long long id = prev[T]; id >= 0; id = prev[e[id].x]) 
				flow = min(flow, e[id].cap - e[id].flow);
			for (long long id = prev[T]; id >= 0; id = prev[e[id].x]) 
			{
				cost += e[id].cost * flow;
				e[id].flow += flow;
				e[id ^ 1].flow -= flow;
			}
		}
		
		return make_pair(flow, cost);
	}
	
	pair <long long,long long> minCostMaxFlow()
	{
		long long totalFlow = 0, totalCost = 0;
		while (1)
		{
			pair <long long,long long> u = dijkstra();
			if (!done[T]) break;
			totalFlow += u.first; totalCost += u.second;
		}
		return make_pair(totalFlow, totalCost);
	}
};

long long flow[111][111], hasEdge[111][111], c[111][111], cc[111][111];

int main()
{
    if (ifstream ("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
	//freopen("i.in", "r", stdin);
	long long n, m, S, T, F, x, y, cap, cost;
	cin >> n >> m >> F >> S >> T;
	MinCostMaxFlow u(n + 2, n + 1, n + 2);
	u.addEdge(n + 1, S, F, 0);
	u.addEdge(T, n + 2, F, 0);
	while (m--)
	{
		cin >> x >> y >> cost >> cap;
		hasEdge[x][y] = hasEdge[y][x] = 1;
		c[x][y] = c[y][x] = cost;
		cc[x][y] = cc[y][x] = cap;
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (cc[i][j] > 0)
				u.addEdge(i, j, cc[i][j], c[i][j]);
	
	pair <long long,long long> ans = u.minCostMaxFlow();
	if (ans.first < F) puts("-1");
	else
	{
		cout << ans.second << endl;
		for (int i = 0; i < int(u.e.size()); i++)
		{
			long long x = u.e[i].x, y = u.e[i].y;
			if (x > y) continue;
			flow[x][y] += u.e[i].flow;
		}
		
		for (long long i = 1; i <= n; i++)
			for (long long j = i + 1; j <= n; j++)
				if (hasEdge[i][j])
				{
					if (flow[i][j] > 0) cout << i << ' ' << j << ' ' << flow[i][j] << endl;
					if (flow[i][j] < 0) cout << j << ' ' << i << ' ' << -flow[i][j] << endl;
				}
		puts("0 0 0");
	}
}
