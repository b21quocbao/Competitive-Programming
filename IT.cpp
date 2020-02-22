template<class T>
class IT
{
    T MAX (T a, T b)
    {
        return a + b;
    }
    void Assign (T& a, T b)
    {
        a += b;
    }
    const T minT = 0;
    public:
        vector<T> it, la;
        int n;
        bool Lazy;
        IT (int N = mn, bool LazY = 0)
        {
            n = N;
            it.resize(4 * n + 10);
            la.resize(4 * n + 10);
            Lazy = LazY;
            clear();
        }   

        void resize (int N)
        {
            n = N;
            it.resize (4 * n + 10);
            la.resize (4 * n + 10);
        }

        void lazy (int id, T w)
        {
            Assign (it[id], w);
            if (!Lazy) return;
            Assign (la[id], w);
        }

        void layd (int id)
        {
            if (!Lazy) return;
            int i = id << 1;
            lazy (i, la[id]);
            lazy (i ^ 1, la[id]);
            la[id] = 0;
        }

        void clear (int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            it[id] = minT;
            if (l == r) return;
            int i = id << 1, m = (l + r) >> 1;
            clear (i, l, m);
            clear (i ^ 1, m + 1, r);
        }

        void ud (int a, int b, T w, int id = 1, int l = 1, int r = - 1)
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

        T qu (int a, int b, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return minT;
            if (l >= a && r <= b)
            return it[id];
            int i = id << 1, m = (l + r) >> 1;
            return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
        }
};