#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TRAINS"

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

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


template<class T>
class IT
{
    T MAX (T a, T b)
    {
        return max (a, b);
    }
    void Assign (T& a, T b)
    {
        a = max (a, b);
    }
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
            if (la[id] == - 1) return;
            int i = id << 1;
            lazy (i, la[id]);
            lazy (i ^ 1, la[id]);
            la[id] = - 1;
        }

        void clear (int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            it[id] = la[id] = - 1;
            if (l == r) return;
            int i = id << 1, m = (l + r) >> 1;
            clear (i, l, m);
            clear (i ^ 1, m + 1, r);
            it[id] = MAX (it[i], it[i ^ 1]);
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
            if (l > b || r < a) return - 1;
            if (l >= a && r <= b)
            return it[id];
            int i = id << 1, m = (l + r) >> 1;
            layd (id);
            return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
        }
};

int rmq[mn][18];
vector<pair<int, int> > e[mn];

void enter()
{
    int n, m, k;
    read (n); read (m); read (k);
    for (int i = 0; i < m; ++ i)
    {
        int s, t, x;
        read (s); read (t); read (x);
        e[x].emplace_back(s, t);
    }
    IT<int> it (n, 1);
    for (int i = 1; i <= k; ++ i)
    {
        sort (e[i].begin(), e[i].end());
        int cur = 1;
        for (int j = 0; j < e[i].size(); ++ j)
        {
            it.ud (cur, e[i][j].first, e[i][j].first);
            cur = e[i][j].second;
        }
        it.ud (cur, n, n);
    }
    memset (rmq, - 1, sizeof (rmq));
    for (int i = 1; i <= n; ++ i)
    {
        rmq[i][0] = it.qu (i, i);
        if (rmq[i][0] <= i) rmq[i][0] = - 1;
    }
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= 17; ++ j)
    if (rmq[i][j - 1] != - 1)
    rmq[i][j] = rmq[rmq[i][j - 1]][j - 1];
    int q;
    read (q);
    for (int i = 0; i < q; ++ i)
    {
        int u, v, sol = 0;
        read (u); read (v);
        for (int i = 17; i >= 0; -- i)
        if (rmq[u][i] > u && rmq[u][i] <= v) 
        {
            u = rmq[u][i];
            sol += (1 << i);
        }
        if (u != - 1 && u < v) 
        {
            u = rmq[u][0];
            ++ sol;
        }
        write (u < v ? - 1 : sol);
        putchar('\n');
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}