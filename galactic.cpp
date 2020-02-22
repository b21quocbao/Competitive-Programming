#include <bits/stdc++.h>

#define int long long 
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long gt[mn];

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
    freopen ("galactic.in", "r", stdin);
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

long long mo (long long r)
{
    r %= mod;
    return ((r < 0) ? r + mod : r);
}

long long po (int n, int k)
{
    if (!k) return 1ll;
    long long r = po (n, k >> 1);
    r = mo (r * r);
    return ((k & 1) ? mo (r * n) : r);
}

inline long long C (int n, int k)
{
    return mo (gt[n] * po (mo (gt[k] * gt[n - k]), mod - 2));
}

void enter()
{
    int n, k;
    cin >> n >> k;
    if (k > n)
    {
        cout << 0 << "\n";
        return;
    }
    swap (n, k);
    int o = 1;
    long long sol = 0;
    for (int i = n; i >= 1; -- i)
    {
        sol += mo (mo (o * po (i, k)) * C (n, i));
        o = - o;
        sol = mo (sol);
    }
    cout << sol << "\n";
}

void solve()
{

}

void print_result()
{

}

int32_t main()
{
    docfile();
    gt[0] = 1;
    for (int i = 1; i < mn; ++ i)
    gt[i] = mo (gt[i - 1] * i);
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}