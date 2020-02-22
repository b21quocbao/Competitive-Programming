#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "CMPENCODE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 98765431;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mn];

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

long long po (int n, int k)
{
    if (!k) return 1ll;
    auto n1 = po (n, k >> 1);
    n1 = (n1 * n1) % mod;
    return ((k % 2) ? (n1 * n) % mod : n1);
}

void enter()
{
    int n, t;
    cin >> n >> t;
    long long s = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        s += a[i];
    }
    s %= mod;
    long long q = ((po (n - 1, t) + ((t % 2) ? 1 : - 1)) * po (n, mod - 2)) % mod;
    cerr << q;
    for (int i = 0; i < n; ++ i)
    {
        cout << (s * q + (t % 2 ? - a[i] : a[i])) % mod << " ";
    }
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