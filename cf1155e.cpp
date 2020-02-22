#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e6) + 3;
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

int a[12][12], p[12];

int po (int x, int n)
{
    if (!n) return 1ll;
    int X = po (x, n >> 1);
    X = (X * X) % mod;
    return (n % 2 ? (X * x) % mod : X);
}

void enter()
{
    int x = 1;
    for (int i = 0; i <= 10; ++ i)
    {
        cout << "? " << x << endl;
        a[i][0] = 1;
        for (int j = 1; j <= 10; ++ j)
        a[i][j] = (a[i][j - 1] * x) % mod;
        cin >> a[i][11] ;
        ++ x;
    }
    for (int i = 1; i <= 10; ++ i)
    {
        for (int k = 0; k < i; ++ k)
        {
            int t1 = a[k][k], t2 = a[i][k];
            for (int j = 0; j <= 11; ++ j)
            {
                a[k][j] = (a[k][j] * - t2) % mod;
                a[i][j] = (a[i][j] * t1) % mod;
                if (a[k][j] < 0) a[k][j] += mod;
            }
            for (int j = 0; j <= 11; ++ j)
            a[i][j] = (a[i][j] + a[k][j]) % mod;
        }
    }
    for (int i = 10; i >= 0; -- i)
    {
        int s = 0;
        for (int j = min (i + 1, 10ll); j > i; -- j)
        s += (a[i][j] * p[j]);
        s %= mod;
        p[i] = ((a[i][11] - s) * po (a[i][i], mod - 2)) % mod;
        if (p[i] < 0) p[i] += mod;
    }
    for (int x = 0; x < mod; ++ x)
    {
        int X = 1, s = p[0];
        for (int i = 1; i <= 10; ++ i)
        {
            X = (X * x) % mod;
            s += (p[i] * X);
        }
        s %= mod;
        if (s) continue;
        cout << "! " << x << endl;
        return;
    }
    cout << - 1 << endl;
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