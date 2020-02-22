#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "DHBB"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
unordered_map<long long, long long> f;
long long x, n, p, v;

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

int F (int n)
{
    int sol = LLONG_MAX;
    for (int k = 1; (1ll << k) <= n; ++ k)
    {
        int x = ceil (pow (n, 1. / k));
        int s = 1;
        for (int i = 1; i <= k; ++ i)
        s *= x;
        int r = k * x;
        while (s / x * (x - 1) >= n)
        {
            s = s / x * (x - 1);
            r = r - x + x - 1;
        }
        sol = min (sol, r * p + k * v);
    }
    return sol;
}

void enter()
{
    if (! (cin >> n >> p >> v))  exit (0);
    f.clear();
    cout << F (n)<< "\n";
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