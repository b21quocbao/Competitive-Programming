class Matching
{
    public:
    int n, m, Time = 0, sol = 0;
    vector<int> match, match1, V, h, ok;
    vector<vector<int> > e;
    Matching (int N, int M) : n (N), m (M) 
    {
        e.resize(n + 2);
        match.resize(m + 2);
        match1.resize(n + 2);
        V.reserve (n + 2);
        for (int i = 1; i <= n; ++ i)
        V.emplace_back(i);
        h.resize(m + 2);
        ok.resize(n + 2);
    }

    void AddEdge (int u, int v)
    {
        e[u].emplace_back(v);
    }

    bool Bfs ()
    {
        queue<int> qu;
        fill(h.begin(), h.end(), 0);
        for (int u : V)
        for (int v : e[u])
        if (!h[v])
        {
            h[v] = 1;
            qu.push (v);
        }
        bool ok = 0;
        while (qu.size())
        {
            int u = qu.front(); qu.pop();
            if (!match[u])
            {
                ok = 1;
                continue;
            }
            for (int v : e[match[u]])
            if (!h[v])
            {
                h[v] = h[u] + 1;
                qu.push (v);
            }
        }
        return ok;
    }

    bool Dfs (int u, int H)
    {
        if (ok[u] == Time) return 0;
        ok[u] = Time;
        for (int v : e[u])
        if (h[v] == H)
        {
            if (!match[v] || Dfs (match[v], H + 1)) 
            {
                match[v] = u;
                match1[u] = v;
                return 1;
            }
        }
        return 0;
    }

    void process ()
    {
        while (Bfs())
        {
            ++ Time;
            for (int i = V.size() - 1; i >= 0; -- i)
            if (Dfs (V[i], 1))
            {
                ++ sol;
                V[i] = V.back();
                V.pop_back();
            }
        }
    }

    int Sol()
    {
        process();
        return sol;
    }
};