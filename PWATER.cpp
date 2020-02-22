#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PWATER"

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int A[mn];
int m;

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

struct Z
{
    int ma, id, sc;
    long long s;
    Z (){ma = - 1; s = 0; sc = 0;}
    Z (int _ma, int _id, long long _s, int _sc)
    {
        ma = _ma; id = _id; s = _s; sc = _sc;
    }
};

template<class T>
class IT
{
    T MAX (T a, T b)
    {
        if (b.ma > a.ma)
        {
            a.ma = b.ma;
            a.id = b.id;
        }
        a.s += b.s;
        a.sc += b.sc;
        return a;
    }
    void Assign (T& a, int b)
    {
        if (a.ma == - 1) return;
        a.s += 1ll * b * a.sc;
        a.ma += b;
    }
    public:
        vector<T> it;
        vector<int> la;
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

        void lazy (int id, int w)
        {
            Assign (it[id], w);
            if (!Lazy) return;
            la[id] += w;
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
            if (l == r) 
            {
                it[id] = {A[l], l, A[l], 1};
                return;
            }
            int i = id << 1, m = (l + r) >> 1;
            clear (i, l, m);
            clear (i ^ 1, m + 1, r);
            it[id] = MAX (it[i], it[i ^ 1]);
        }

        void del (int x, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > x || r < x) return;
            if (l == r)
            {
                it[id].s = m;
                it[id].ma = - 1;
                it[id].sc = 0;
                return;
            }
            int i = id << 1, m = (l + r) >> 1;
            layd (id);
            del (x, i, l, m);
            del (x, i ^ 1, m + 1, r);
            it[id] = MAX (it[i], it[i ^ 1]);
        }

        void ud (int a, int b, int w, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return;
            if (l >= a && r <= b)
            {
                while (it[id].ma != - 1 && it[id].ma >= m - w)
                del (it[id].id);
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
            if (l > b || r < a) return {0, 0, 0, 0};
            if (l >= a && r <= b)
            return it[id];
            int i = id << 1, m = (l + r) >> 1;
            layd (id);
            return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
        }
};

void enter()
{
    int n, k;
    read (n); read (m); read (k);
    for (int i = 1; i <= n; ++ i)
    read (A[i]);
    IT<Z> sol (n, 1);
    for (int i = 0; i < k; ++ i)
    {
        int c, l, r, w;
        read (c); read (l); read (r);
        if (c == 1)
        {
            read (w);
            sol.ud (l, r, w);
        }
        else 
        {
            write (sol.qu(l, r).s);
            putchar ('\n');
        }
    }
}

void solve()
{

}

void print_result()
{

}

main()
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