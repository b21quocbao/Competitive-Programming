class BFS
{
    public:
    vector<vector<int> > e;
    vector<int> d;
    int n, m;

    BFS (int N, int M) : n (N), m (M)
    {
        e.resize(n + 2);
        d.resize(n + 2);
    }

    void AddEdge (int u, int v, bool Directed = 0)
    {
        e[u].emplace_back(v);
        if (!Directed)
        e[v].emplace_back(u);
    }

    int process (int u = 1, int v = 1)
    {
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
                qu.push (v);
            }
        }
        return d[v];
    }

    int ShortestPath(int v)
    {
        return d[v];
    }
};