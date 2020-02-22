class BridgeAcc 
{
    public:
    int Bridge = 0, Node = 0, cn = 0;
    vector<int> low, num;
    void dfs (int u, int w)
    {
        num[u] = low[u] = ++ cn;
        int nc = 0;
        bool Ok = 0;
        for (int v : e[u])
        if (v != w)
        {
            if (!num[v]) 
            {
                ++ nc;
                dfs (v, u);
                low[u] = min (low[u], low[v]);
                if (low[v] >= num[v])
                ++ Bridge;      
                if (low[v] >= num[u])
                Ok = 1;
            }
            else low[u] = min (low[u], num[v]);
        }
        if (!w) 
        {
            if (nc >= 2) Ok = 1;
            else Ok = 0;
        }
        if (Ok) ++ Node;
    }
    BridgeAcc (int n)
    {
        low.resize(n + 2);
        num.resize(n + 2);
        for (int u = 1; u <= n; ++ u)
        if (!num[u])
        dfs (u, 0);
    }
};