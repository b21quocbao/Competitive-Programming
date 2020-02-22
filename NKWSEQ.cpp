#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "NKWSEQ"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 666013;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int pr[mn], cn[mn];

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

int po (int x, int n)
{
    if (!n) return 1;
    long long X = po (x, n >> 1);
    X = (X * X) % mod;
    return (n % 2 ? (1ll * X * x) % mod : X);
}

int C (int k, int n)
{
    if (n < k) return 0;
    for (int i = 1; i <= n; ++ i)
    {
        int j = i;
        while (j != 1)
        {
            ++ cn[pr[j]];
            j /= pr[j];
        }
    }
    for (int i = 1; i <= n - k; ++ i)
    {
        int j = i;
        while (j != 1)
        {
            -- cn[pr[j]];
            j /= pr[j];
        }
    }
    for (int i = 1; i <= k; ++ i)
    {
        int j = i;
        while (j != 1)
        {
            -- cn[pr[j]];
            j /= pr[j];
        }
    }
}

void eros (int N)
{
    for (int i = 2; i * i <= N; ++ i)
    if (!pr[i])
    for (int j = i * i; j <= N; j += i)
    pr[j] = i;
    for (int i = 2; i <= N; ++ i)
    if (!pr[i])
    pr[i] = i;
}

void enter()
{
    int n, k, w;
    cin >> n >> k >> w;
    eros (1000000);
    C (k, n - (k - 1) * w + (k - 1));
    long long sol = 1;
    for (int i = 1; i <= 1000000; ++ i)
    if (cn[i])
    sol = (sol * po (i, cn[i])) % mod;
    cout << sol;
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