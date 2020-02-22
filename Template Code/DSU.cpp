class DSU
{
    public:
        int n;
        vector<int> fa;
        int sol = 0;
        DSU () {}

        DSU (int N) : n (N) 
        {
            fa.resize(n + 2, - 1);
        }

        void resize (int N)
        {
            n = N;
            fa.resize(n + 2, - 1);
        }

        int Fa (int u)
        {
            return (fa[u] < 0 ? u : fa[u] = Fa (fa[u]));
        }

        bool Uni (int u, int v)
        {
            u = Fa (u); v = Fa (v);
            if (u == v) return 0;
            ++ sol;
            if (fa[u] > fa[v]) swap (u, v);
            fa[u] += fa[v];
            fa[v] = u;
            return 1;
        }
};