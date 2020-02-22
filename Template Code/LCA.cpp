class LCA
{
    vector<int> nc, h, fa, he, chin;
    int nch, n, cnt;
    vector<vector<int>> e;
    LCA (int n)
    {
        nc.resize(n + 1);
        h.resize(n + 1);
        fa.resize(n + 1);
        he.resize(n + 1);
        chin.resize(n + 1);
    }
    int chil(const int& di)
    {
        nc[di] = 1;
        for (const int& v: e[di])
        {
            if (!nc[v])
            {
                nc[di] += chil(v);
                fa[v] = di;
            }
        }
        return nc[di];
    }
    void hld(const int& u)
    {
        if (!he[nch]) he[nch] = u;
        chin[u] = nch;
        int re = -1;
        for (const int& v : e[u])
        {
            if (fa[u] != v)
            if (re == -1 || nc[v] > nc[re]) re = v;
        }
        if (re != -1) hld(re);
        for (const int& v : e[u])
        if (fa[u] != v && v != re)
        {
            ++nch;
            hld(v);
        }
    }
    void dfs(const int& di, const int& cs)
    {
        h[di] = cs;
        for (const int& v : e[di])
        {
            if (v != fa[di])
            dfs(v, cs + 1);
        }
    }
    int lca (int u, int v)
    {
        while (chin[u] != chin[v])
        if (h[he[chin[u]]] > h[he[chin[v]]])
        u = fa[he[chin[u]]];
        else v = fa[he[chin[v]]];
        if (h[u] > h[v]) return v;
        return u;
    }
}