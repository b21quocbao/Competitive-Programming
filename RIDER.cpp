#include <bits/stdc++.h>

#define fn "test"
#define fn1 "RIDER"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
int t[mn], id[mn];

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
        freopen(fn1".ans", "w", stdout);
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
    int m, n;
    read (m);
    for (int i = 1; i <= m; ++ i)
    {
        read (t[i]);
        id[i] = i;
    }
    read (n);
    sort (id + 1, id + m + 1, [](int i, int j)
         {
             return t[i] > t[j];
         });
    for (int j = 1; j <= n; ++ j)
    {
        int x;
        read (x);
        long long sol = (long long)(1e18);
        for (int i = 1; i <= m; ++ i)
        if (t[i] > x)
        sol = min (sol, (long long)1e12 * i / (t[i] - x));
        // for (int i = 1; (i <= m) && (t[id[i]] > x); ++ i)
        // sol = min (sol, (long double)1 * id[i] / (t[id[i]] - x));
    }
    cerr << 0x3f3f3f3f << "\n";
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