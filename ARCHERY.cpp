#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ARCHERY"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
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

void ud (int id, int l, int r, int i, int a, int b)
{
    if (l > i || r < i) return;
    if (l == r)
    {
        it1[id] = min (it1[id], a - b);
        it2[id] = max (it2[id], a + b);
        return;
    }
    int Id = (id << 1), m = (l + r) >> 1;
    ud (Id, l, m, i, a, b);
    ud (Id ^ 1, m + 1, r, a, b);
}

int que (int id, int l, int r, int a, int b)
{
    if (l == r)
    {

    }
    if (it1[id] < )
}

void enter()
{
    read (n);
    for (int i = 0; i < n; ++ i)
    {
        read (c); read (x); read (y);
        ++ m;
        if (c == 1)
        ud (1, 1, 200000, m, x, y);
        if (c == 2)
        cout << que (1, 1, 200000, x, y) << "\n";
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