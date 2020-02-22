#include <bits/stdc++.h>

#define fn "test"
#define fn1 "FQUEUE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
int a[mn];

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
bool read(T& x)
{
    x = 0; T f = 1;
    int cn = 0;
    char ch = getchar();
    while (!isdigit(ch)) 
    {
        f = ch == '-' ? - f : f, ch = getchar();
        if (++ cn == 5) return 0;
    }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
    return 1;
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
        a += b;
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
            int i = id << 1;
            lazy (i, la[id]);
            lazy (i ^ 1, la[id]);
            la[id] = 0;
        }

        void clear (int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            it[id] = a[l];
            if (l == r) return;
            int i = id << 1, m = (l + r) >> 1;
            clear (i, l, m);
            clear (i ^ 1, m + 1, r);
            it[id] = MAX (it[i], it[i ^ 1]);
        }

        void ud (int a, int b, T w, int id = 1, int l = 1, int r = - 1)
        {
            if (a > b) return;
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
            if (l > b || r < a) return 0;
            if (l >= a && r <= b)
            return it[id];
            int i = id << 1, m = (l + r) >> 1;
            layd (id);
            return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
        }
        int Get (int x, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (x > it[id]) return r + 1;
            if (l == r) return l;
            int i = id << 1, m = (l + r) >> 1;
            layd (id);
            if (it[i] >= x)
            return Get (x, i, l, m);
            return Get (x, i ^ 1, m + 1, r);
        }
};

void enter()
{
    int n, m;
    if (!read (n)) exit (0);
    read (m);
    for (int i = 1; i <= n; ++ i)
    {
        read (a[i]);
        // cerr << a[i] << "\n";
    }
    sort (a + 1, a + n + 1);
    IT<int> sol (n, 1);
    for (int i = 0; i < m; ++ i)
    {
        char c;
        for (c = getchar(); !isalpha(c); c = getchar()) {}
        bool ok = 0;
        for (; isalpha(c); c = getchar()) {if (c == 'C') ok = 1;}
        if (ok)
        {
            int l, r;
            read (l); read (r);
            cout << sol.Get (r + 1) - sol.Get (l) << "\n";
        }
        else
        {
            int c, h;
            read (c); read (h);
            int l = sol.Get (h); 
            if (l + c - 1 >= n)
            {
                sol.ud (l, l + c - 1, 1);
                continue;
            }
            int ma = sol.qu (l + c - 1, l + c - 1);
            int r = sol.Get (ma);
            int d = l + c - r;
            int k = sol.Get (ma + 1);
            sol.ud (l, r - 1, 1);
            sol.ud (k - d, k - 1, 1);
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