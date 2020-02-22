class MaxFlow
{
    public:
    
    int n, m, s, t;
    queue<int> qu;
    vector<int> cn, h, ex;
    struct Z
    {
        int v,  f,  c,  t;
        Z () {}
        Z (int V, int F, int C, int T) : v (V), f (F), c (C), t (T) {}
    };
    vector<vector<Z>::iterator > cur; 
    vector<Z> e[mn];
    void AddE (int u, int v, int c, bool ok = 0)
    {
        e[u].emplace_back(v, 0, c, e[v].size());
        if (!ok)
        e[v].emplace_back(u, 0, 0, e[u].size() - 1);
        else
        e[v].emplace_back(u, 0, c, e[u].size() - 1);
    }
    MaxFlow (int N, int M, int S, int T) : 
    n (N), m (M), s (S), t (T) 
    {
        cn.resize (2 * n + 2);
        h.resize(n + 2, 1);
        ex.resize(n + 2);
        cur.resize(n + 2);
    }

    void Argue (int u, Z& v, int c)
    {
        ex[u] -= c;
        ex[v.v] += c;
        v.f += c;
        e[v.v][v.t].f -= c;
    }

    void Init()
    {
        for (auto& u : e[s])
        {
            Argue (s, u, u.c);
            if (u.v != t)
            qu.emplace (u.v);
        }
        for (int i = 1; i <= n; ++ i)
        cur[i] = e[i].begin();
        h[s] = n;
        h[t] = 0;
        cn[1] = n - 2;
        cn[n] = cn[0] = 1;
    }

    void UdH (int u, int H)
    {
        -- cn[h[u]];
        h[u] = H;
        ++ cn[H];
    }

    void Gap (int H)
    {
        if (H <= 0 || H >= n || cn[H]) return;
        for (int u = 1; u <= n; ++ u)
        if (h[u] > H && h[u] <= n && u != s)
        {
            UdH (u, n + 1);
            cur[u] = e[u].begin();
        }
    }

    void Lift (int u)
    {
        int minH = 2 * n;
        for (auto v : e[u])
        if (v.c > v.f)
        minH = min (minH, h[v.v] + 1);
        int r = h[u];
        UdH (u, minH);
        Gap (r);
    }

    void Push (int u, vector<Z>::iterator r)
    {
        int mi = min (r->c - r->f, ex[u]);
        Argue (u, *r, mi);
    }

    void process ()
    {
        while (qu.size())
        {
            int u = qu.front(); qu.pop();
            for (; cur[u] != e[u].end(); ++ cur[u])
            {
                auto r = cur[u];
                if (r->f == r->c) continue;
                if (h[u] <= h[r->v]) continue;
                if (!ex[r->v] && r->v != s && r->v != t) qu.emplace (r->v);
                Push (u, r);
                if (!ex[u]) break;
            }
            if (ex[u])
            {
                Lift (u);
                cur[u] = e[u].begin();
                qu.push (u);
            }
        }
    }

    int Sol ()
    {
        Init();
        process();
        return ex[t];
    }

};