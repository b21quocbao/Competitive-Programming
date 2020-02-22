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

long long gt = 1;
long long a[30];
int lo[1 << 20], deg[1 << 20];
long long r[1 << 20];
int t = 0;

int C (long long n, int k)
{
    if (n < k) return 0;
    long long x = gt;
    long long s = 1;
    for (long long i = n - k + 1; i <= n; ++ i)
    s = (s * (i % mod)) % mod; 
    return s;
}

int po (int n, int k)
{
    if (!k) return 1;
    long long N = po (n, k >> 1);
    N = (N * N) % mod;
    return ((k & 1) ? (N * n) % mod : N);
}

void enter()
{
    int n; long long s;
    cin >> n >> s;
    s += n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        ++ a[i];
    }
    for (int i = 1; i < n; ++ i)
    gt = (gt * i) % mod;
    for (int i = 0; i < n; ++ i)
    lo[1 << i] = i;
    int sol = 0;
    deg[0] = 1;
    for (int i = 0; i < (1 << n); ++ i)
    {
        if (i)
        {
            r[i] = r[i - (i & - i)] + a[lo[i & - i]];
            deg[i] = - deg[i - (i & - i)];
        }
        sol += deg[i] * C (s - r[i] - 1, n - 1);
        if (sol < 0) sol += mod;
        if (sol >= mod) sol -= mod;
    }
    cout << (1ll * sol * po (gt, mod - 2)) % mod;
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