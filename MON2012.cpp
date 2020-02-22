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

struct Node
{
    int l, r;
    int v;
    Node (){}
} it[20 * mn];
int Nnode = 1;

void lazy (int id, int l, int r)
{
    it[id].v = r - l + 1;
}

void layd (int id, int l, int r)
{
    if (it[id].v != (r - l + 1)) return;
    int m = (l + r) >> 1;
    lazy (it[id].l, l, m);
    lazy (it[id].r, m + 1, r);
}

void ud (int a, int b, int id = 1, int cha = 0, int l = 1, int r = base, bool Left = 1)
{
    if (l > b || r < a) return;
    if (it[id].v == r - l + 1) return;
    if (l >= a && r <= b)
    {
        lazy (id, l, r);
        return;
    }
    int m = (l + r) >> 1;
    if (!it[id].l) it[id].l = ++ Nnode;
    if (!it[id].r) it[id].r = ++ Nnode;
    layd (id, l, r);
    ud (a, b, it[id].l, id, l, m, 1);
    ud (a, b, it[id].r, id, m + 1, r, 0);
    it[id].v = (it[it[id].l].v + it[it[id].r].v);
}

int qu (int a, int b, int id = 1, int l = 1, int r = base)
{
    if (!id) return 0;
    if (l > b || r < a) return 0;
    if (it[id].v == (r - l + 1)) 
    return (min (b, r) - max (a, l) + 1);
    if (l >= a && r <= b) return it[id].v;
    int m = (l + r) >> 1;
    layd (id, l, r);
    return qu (a, b, it[id].l, l, m) + qu (a, b, it[id].r, m + 1, r);
}

void enter()
{
    int n, c = 0;
    read (n);
    for (int i = 0; i < n; ++ i)
    {
        int id, l, r;
        read (id); read (l); read (r);
        if (id == 2) ud (l + c, r + c);
        else cout << (c = qu (l + c, r + c)) << '\n';
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