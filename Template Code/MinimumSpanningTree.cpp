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

template <class T>
class Kruskal
{
    public:
    const T minT = 0;
    void MAX (T& a, T b)
    {
        a = max (a, b);
    }
    DSU Tree;
    T sol = minT;
    int n;
    struct Z
    {
        T c;
        int u, v;
        Z (){}
        Z (T C, int U, int V) : c (C), u (U), v (V) {}
        bool operator < (Z x)
        {
            return c < x.c;
        }
    };
    vector<Z> d;
    Kruskal (int N) : n (N) 
    {
        Tree.resize(n);   
    }

    void AddEdge(int u, int v, int c)
    {
        d.emplace_back(c, u, v);
    }

    bool process ()
    {
        sort (d.begin(), d.end());
        for (auto i : d)
        {
            if (Tree.Uni (i.u, i.v)) MAX (sol, i.c);
            if (Tree.sol == n - 1) return 1;
        }
        return 0;
    }
};