#include <bits/stdc++.h>

#define int  long long 
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[20];
long long a[mn];

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

inline int mo (long long r)
{
    return r % mod;
}

int po (int n)
{
    if (!n) return 1;
    long long r = po (n >> 1);
    r = mo (r * r);
    return ((n & 1) ? mo (r * 10) : r);
}

inline int scs (long long n)
{
    int s = 0;
    while (n)
    {
        ++ s;
        n /= 10;
    }
    return s;
}

void enter()
{
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        ++ d[scs (a[i])];
        a[i] %= mod;
    }
    long long sol = 0;

    for (int i = 0; i < n; ++ i)
    {
        int x = a[i];
        int r = scs (a[i]);
        -- d[r];
        for (int i = 1; i < 20; ++ i)
        sol = mo (sol + (d[i] * (po (i) * x) % mod) % mod);
        sol = mo (sol + a[i] * (n - 1));
        ++ d[r];
        sol %= mod;
    }
    cout << sol;
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}