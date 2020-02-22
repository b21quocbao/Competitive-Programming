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
int n, q1, q2;
int ita[4 * mn], ito[4 * mn];

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

void ud (int x, int z, int id = 1, int l = 0, int r = n - 1)
{
    if (l > x || r < x) return;
    if (l == r)
    {
        ito[id] = z;
        ita[id] = z;
        return;
    }
    int m = (l + r) >> 1;
    ud (x, z, id << 1, l, m);
    ud (x, z, (id << 1) ^ 1, m + 1, r);
    ito[id] = ito[id << 1] | ito[(id << 1) ^ 1]; 
    ita[id] = ita[id << 1] & ita[(id << 1) ^ 1]; 
}

pair<int, int> qu (int x, int y, int id = 1, int l = 0, int r = n - 1)
{
    if (l > y || r < x) return {(1<<30) - 1, 0};
    if (l >= x && r <= y) return {ita[id], ito[id]};
    int m = (l + r) >> 1;
    auto r1 = qu (x, y, id << 1, l, m), r2 = qu (x, y, (id << 1) ^ 1, m + 1, r); 
    return {r1.first & r2.first, 
            r1.second | r2.second};
}

void enter()
{
    read (n); read (q1); read (q2);
    for (int i = 0; i < n; ++ i)
    {
        int x;
        read (x);
        ud (i, x);
    }    
    for (int i = 0; i < q1 + q2; ++ i)
    {
        int t;
        read (t);
        if (t == 1)
        {
            int x, z;
            read (x); read (z);
            -- x;
            ud (x, z);
        }
        else
        {
            int l, r;
            read (l); read (r);
            -- l; -- r;
            auto re = qu (l, r);
            write (re.first + re.second);
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