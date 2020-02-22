#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<pair<int, int> > e[mn];
int u[mn], v[mn], c[mn];

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

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
void write (T a)
{
    if (a < 0)
    {
        putchar ('-');
        write (-a);
        return;
    }
    if (a < 10)
    {
        putchar ('0' + a);
        return;
    }
    write (a / 10);
    putchar ((char)('0' + (a % 10)));
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    e[i].clear();
    for (int i = 1; i < n; ++ i)
    {
        cin >> u[i] >> v[i] >> c[i];
        e[u[i]].emplace_back(c[i], v[i]);
        e[v[i]].emplace_back(c[i], u[i]);   
    }
    HLD<int> Gr (n);
    for (int i = 1; i < n; ++ i)
    {
        if (Gr.Fa[v[i]] == u[i]) swap (u[i], v[i]);
        Gr.it.ud (Gr.Num[u[i]], Gr.Num[u[i]], c[i]);
    }
    while (1)
    {
        string s;
        cin >> s;
        int i, w;
        if (s[0] == 'D') break;
        else cin >> i >> w;
        if (s[0] == 'C')
        Gr.it.ud (Gr.Num[u[i]], Gr.Num[u[i]], w);
        else 
        cout << Gr.Qu (i, w) << "\n";
    }
}

void solve()
{

}

void print_result()
{

}

int main()
{
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}