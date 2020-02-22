class DFS
{
    public:
    int n, m;
    vector<int> h, sc, fa;
    vector<vector<int> > e;
    void AddEdge (int u, int v, bool Directed = 0)
    {
        e[u].emplace_back (v);
        if (!Directed)
        e[v].emplace_back(u);
    }
    void dfs (int u)
    {
        sc[u] = 1;
        for (int v : e[u])
        if (!h[v] && v != 1)
        {
            h[v] = h[u] + 1;
            fa[v] = u;
            sc[u] += sc[v];
            dfs (v);
        }
    }
    DFS (int N, int M = 0, int u = 1) : n (N), m (M)
    {
        h.resize(n + 2);
        sc.resize(n + 2);
        fa.resize(n + 2);
        e.resize(n + 2);
    }
    void process (int u = 1)
    {
        dfs (u);
    }
};