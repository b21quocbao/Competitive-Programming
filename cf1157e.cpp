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

int it[4 * mn], cn[4 * mn], Cn[mn], a[mn], b[mn], n;

int qu (int id, int l, int r, int a, int b)
{
    if (l > b || r < a) return n;
    if (l >= a && r <= b) return it[id];
    int m = (l + r) >> 1, i = id << 1;
    return min (qu (i, l, m, a, b), qu (i + 1, m + 1, r, a, b));
}

void ud (int id, int l, int r, int x)
{
    if (l > x || r < x) return;
    if (l == r)
    {
        if (-- cn[id] == 0) it[id] = n;
        return;
    }
    int m = (l + r) >> 1, i = id << 1;
    ud (i, l, m, x); ud (i + 1, m + 1, r, x);
    it[id] = min (it[i], it[i + 1]);
}

void InitIt (int id, int l, int r)
{
    if (l == r)
    {
        cn[id] = Cn[l];
        if (cn[id]) it[id] = l; else it[id] = n;
        return;
    }
    int m = (l + r) >> 1, i = id << 1;
    InitIt (i, l, m); InitIt (i + 1, m + 1, r);
    it[id] = min (it[i], it[i + 1]);
}

void enter()
{
    cin >> n;   
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    {
        cin >> b[i];
        ++ Cn[b[i]];
    }
    InitIt(1, 0, n - 1);
    for (int i = 1; i <= n; ++ i)
    {
        int d = qu (1, 0, n - 1, n - a[i], n - 1);
        if (d == n) d = qu (1, 0, n - 1, 0, n - a[i] - 1);
        ud (1, 0, n - 1, d);
        cout << (d + a[i]) % n << " ";
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