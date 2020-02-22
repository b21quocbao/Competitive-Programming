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

int gt[2 * mn];

int mul (int a, int b)
{
    return (a * b) % mod;
}

int po (int n, int k)
{
    if (!k) return 1;
    int r = po (n, k >> 1);     
    r = mul (r, r);
    return (k % 2 ? mul (r, n) : r);
}

int C (int n, int k)
{
    return mul (gt[n], po (mul (gt[k], gt[n - k]), mod - 2));
}

int D (int i, int j, int m, int n)
{
    m -= i; n -= j;
    return C (m + n, m);
}

int mo (int n)
{
    n %= mod;
    if (n < 0) n += mod;
    return n;
}

void enter()
{
    int n, m, r, c;
    cin >> m >> n;
    cin >> r >> c;
    cout << mo (D (1, 1, m, n) - mul (D (1, 1, r, c), D (r, c, m, n))) << "\n";
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
    for (int i = 1; i < 2 * mn; ++ i)
    gt[i] = mul (gt[i - 1], i);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}