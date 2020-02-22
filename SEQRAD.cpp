#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SEQRAD"

using namespace std;

const int mn = 2 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long a[mn], b[mn], x[mn];

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

void enter()
{
    int n, k, m;
    read (n); read (k); read (m);
    for (int i = 0; i < m; ++ i)
    read (a[i]);
    for (int i = 0; i < m; ++ i)
    read (b[i]);
    for (int i = 0; i < n; ++ i)
    x[i] = a[i % m] ^ b[i / m];
    long long inf = 0, sup = (1ll << 60) - 1, sol;
    while (inf <= sup)
    {
        long long mid = (inf + sup) >> 1;
        int cn = 1;
        long long mi = LLONG_MAX, ma = LLONG_MIN;
        for (int i = 0; i < n; ++ i)
        {
            mi = min (mi, x[i]);
            ma = max (ma, x[i]);
            if (ma - mi > mid)
            {
                mi = ma = x[i];
                ++ cn;
            }
        }
        if (cn <= k)
        {
            sol = mid;
            sup = mid - 1;
        }
        else inf = mid + 1;
    }
    cout << (sol + 1) / 2;
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