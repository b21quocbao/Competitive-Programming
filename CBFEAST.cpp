#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

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

struct Z
{
    int l, r;
    int S, L, R, V;
    Z (){}
    void operator += (const int& x)
    {
        S += x;
        L = max (L, S);
        R = max (0, R + x);
        V = max (V, R);  
    }
    void operator += (const Z& a)
    {
        V = max (V, max (a.V, R + a.L));
        L = max (L, S + a.L);
        R = max (a.R, a.S + R);
        S += a.S;
    }

    Z operator + (const Z& a)
    {
        (*this) += a;
        return (*this);
    }

    void clear()
    {
        S = L = R = V = 0;
    }
};

Z c;

struct IT
{
    Z it[32 * mn]; 
    int N = 1;
    void layd (int id)
    {
        if (!it[id].l) it[id].l = ++ N;
        if (!it[id].r) it[id].r = ++ N;
        it[it[id].l] += it[id];
        it[it[id].r] += it[id];
        it[id].clear();
    }

    void ud (int a, int b, int w, int id = 1, int l = 0, int r = base)
    {
        if (l > b || r < a) return;
        if (l >= a && r <= b)
        {
            it[id] += w;
            return;
        }
        layd (id);
        int m = (l + r) >> 1;
        ud (a, b, w, it[id].l, l, m);
        ud (a, b, w, it[id].r, m + 1, r);
    }
    
    Z qu (int x, int id = 1, int l = 0, int r = base)
    {
        if (!id) return c;
        if (l == r) return it[id];
        int m = (l + r) >> 1;
        layd (id);
        if (x <= m) return qu (x, it[id].l, l, m);
        return qu (x, it[id].r, m + 1, r);
    }
} it[2];


void enter()
{
    int q, k;
    int sol = 0;
    read (q); read (k);
    for (int i = 0; i < q; ++ i)
    {
        int id, c, d;
        read (id); read (c);
        c ^= sol;
        if (id == 3)
        {
            auto k1 = it[0].qu (c), k2 = it[1].qu (c);
            write (sol = max(max (k1.V, k2.V), k1.L + k2.L));
            putchar ('\n');
        }
        else
        {
            read (d);
            it[id - 1].ud (max (c - k, 0), min (c + k, base), d);
        }
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