int MAX (int a, int b)
{
    return max (a, b);
}

template<class DT>
class IT
{
    const DT minDT = 0;
    private:
        vector<DT> it, la;
        int n;
    public:
        IT (){}
        IT (int n)
        {
            it.resize(4 * n + 10);
            la.resize(4 * n + 10);
        }   

        void resize (int N)
        {
            n = N;
            it.resize (4 * n + 10);
            la.resize (4 * n + 10);
        }

        void lazy (int id, DT w)
        {
            it[id] = w;
            la[id] += w;
        }

        void layd (int id)
        {
            int i = id << 1;
            lazy (i, la[id]);
            lazy (i ^ 1, la[id]);
            it[id] = 0;
        }

        void clear (int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            it[id] = minDT;
            if (l == r) return;
            int i = id << 1, m = (l + r) >> 1;
            clear (i, l, m);
            clear (i ^ 1, m + 1, r);
        }

        void ud (int a, int b, DT w, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return;
            if (l >= a && r <= b)
            {
                lazy (id, w);
                return;
            }
            int m = (l + r) >> 1, i = id << 1;
            layd (id);
            ud (a, b, w, i, l, m);
            ud (a, b, w, i ^ 1, m + 1, r);
            it[id] = MAX (it[i], it[i ^ 1]);
        }

        DT qu (int a, int b, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return minDT;
            if (l >= a && r <= b)
            return it[id];
            int i = id << 1, m = (l + r) >> 1;
            return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
        }
};

template<class DT>
class HLD
{
    public:
        const DT minDT = 0;
        int CurStart = 0, CurNum = 0, n;
        vector<int> h, sc, Num, Head;
        void Dfs (int u)
        {
            sc[u] = 1;
            for (auto v : e[u])
            if (v.second != Fa[u])
            {
                Fa[v.second] = u;
                h[v.second] = h[u] + 1;
                Dfs (v.second);
                sc[u] += sc[v.second];
            }
        }
        void ReNum(int u)
        {
            if (!CurStart) CurStart = u;
            Head[u] = CurStart;
            Num[u] = ++ CurNum;
            int FatNode = - 1;
            for (auto v : e[u])
            if (v.second != Fa[u])
            if (FatNode == - 1 || sc[v.second] > sc[FatNode])
            FatNode = v.second; 
            if (FatNode != - 1) ReNum (FatNode);
            for (auto v : e[u])
            if (v.second != Fa[u] && v.second != FatNode)
            {
                CurStart = 0;
                ReNum (v.second);
            }
        }
        int Lca (int u, int v)
        {
            while (Head[u] != Head[v])
            {
                if (h[Head[u]] > h[Head[v]])
                u = Fa[Head[u]];
                else
                v = Fa[Head[v]];
            } 
            return (h[u] > h[v] ? v : u);
        }
        void ud (int u, int v, int w)
        {
            while (Head[u] != Head[v])
            {
                it.ud (Num[Head[u]], Num[u]);
                u = Fa[Head[u]];
            }
            it.Ud (Num[v] + 1, Num[u], w);
        }
        DT qu (int u, int v)
        {
            DT r = minDT;
            while (Head[u] != Head[v])
            {
                r = MAX (r, it.qu (Num[Head[u]], Num[u]));
                u = Fa[Head[u]];
            }
            r = MAX (r, it.qu (Num[v] + 1, Num[u]));
            return r;
        }
    public:
        IT<DT> it;
        vector<int> Fa;
        HLD(int n, int u = 1)
        {
            it.resize(n);
            it.clear();
            Fa.resize (n + 2);
            Head.resize(n + 2);
            Num.resize (n + 2);
            sc.resize(n + 2);
            h.resize (n + 2);
            Dfs (u);
            ReNum (u);
        }
        void Ud (int u, int v, DT w)
        {
            int lc = Lca (u, v);
            ud (u, lc, w);
            ud (v, lc, w);
        }
        DT Qu (int u, int v)
        {
            int lc = Lca (u, v);
            return MAX (qu (u, lc), qu (v, lc));
        }
};
