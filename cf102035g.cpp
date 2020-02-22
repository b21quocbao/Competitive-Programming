#include <bits/stdc++.h>
#define int long long

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

int pr[mn], cn[mn], gt[mn], a[mn];

long long po (const int& n, const int& k)
{
    if (!k) return 1;
    long long a = po (n, k >> 1);
    a = (a * a) % mod;
    return (k & 1 ? (a * n) % mod : a);
}

long long C (int n, int k)
{
    if (n < k) return 0;
    return (((gt[n] * po (gt[k], mod - 2)) % mod) * po (gt[n - k], mod - 2)) % mod;
}

void enter()
{
    int n, k;
    cin >> n >> k;
    if (k % 2)
    {
        cout << 0 << "\n";
        return;
    }
    long long s = 0;
    int l = (n - k) / k + 1;
    for (int i = max (k / 2 - (n - n % k), 0ll); i <= min (k / 2, n % k); ++ i)
    {
        // cerr << (k / 2) * l + i << "\n";
        s = s + ((C (n % k, i) * C (k - n % k, k / 2 - i)) % mod * po (2, (k / 2) * l + i)) % mod;
        s %= mod;
    }   
    cout << s << "\n";
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
    cin>>ntest;
    gt[0] = 1;
    for (int i = 1; i <= 100000; ++ i)
    gt[i] = (gt[i - 1] * i) % mod;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}