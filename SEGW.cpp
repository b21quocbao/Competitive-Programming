#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SEGW"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mn], w[mn], cur[mn], nex[mn], cn[mn];
long long c[mn];

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
            it[id] = c[l];
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
            if (l > b || r < a) return 0;
            if (l >= a && r <= b)
            return it[id];
            int i = id << 1, m = (l + r) >> 1;
            layd (id);
            return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
        }
};

void enter()
{
    int n, m;
    read (n); read (m);
    for (int i = 1; i <= n; ++ i)
    {
        read (a[i]);
        cur[a[i]] = n + 1;
    }
    for (int i = 1; i <= m; ++ i)
    read (w[i]);
    for (int i = n; i >= 1; -- i)
    nex[i] = cur[a[i]], cur[a[i]] = i;
    for (int i = 1; i <= n; ++ i)
    {
        int d = (++ cn[a[i]]);
        if (d == 1) c[i] = c[i - 1] + w[a[i]];
        else if (d == 2) c[i] = c[i - 1] - w[a[i]];
        else c[i] = c[i - 1];
        // cerr << c[i] << "\n";
    }
    // cout << c[n];
    IT<long long> sol (n, 1);
    long long Sol = sol.qu (1, n);
    for (int i = 1; i <= n; ++ i)
    {
        sol.ud (i, nex[i] - 1, - w[a[i]]);
        if (nex[i] <= n)
        sol.ud (nex[i], nex[nex[i]] - 1, w[a[i]]);
        Sol = max (Sol, sol.qu (1, n));
    }
    cout << Sol;
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