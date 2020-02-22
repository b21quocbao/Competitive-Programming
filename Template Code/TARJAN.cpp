class Tarjan
{
    public:
    vector<int> num, low;
    vector<vector<int> > sol;
    vector<int> v;
    int cn = 0;
    void dfs (int u, int w)
    {
        num[u] = low[u] = ++ cn;
        v.emplace_back (u);
        for (int v : e[u])
        if (v != w)
        {
            if (!num[v]) dfs (v, u);
            low[u] = min (low[u], low[v]);
        }
        if (num[u] == low[u])
        {
            vector<int> r;
            while (1)
            {
                int k = v.back();
                v.pop_back();
                num[k] = low[k] = (int)(1e9);
                r.emplace_back(k);
                if (k == u) break;
            }
            sol.emplace_back (r);
        }
    }
    Tarjan (int n)
    {
        num.resize(n + 2);
        low.resize(n + 2);
        for (int u = 1; u <= n; ++ u)
        if (!num[u])
        dfs (u, 0);
    }
    int Sol()
    {
        return sol.size();
    }
};