#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""
#define int long long

using namespace std;

const int mn = 4 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[mn];
int ok[mn];

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
    long long h, l;
    int k;
    cin >> h >> l >> k;
    
    int s = 1;
    for (int i = 1; i <= k; ++ i)
    s = (s * i) / __gcd (s, i);
    int cn = 1;
    bool Ok = 1;
    while (h != l)
    {
        if (Ok)
        if (ok[h % s] && Ok)
        {
            Ok = 0;
            int d = cn - ok[h % s];
            if (h % s >= l % s)
            {
                cn += d * (h / s - l / s);
                h -= s * (h / s - l / s);
            }
            else
            {
                cn += d * (h / s - l / s - 1);
                h -= s * (h / s - l / s - 1);
            }
            continue;
        }
        ok[h % s] = cn;
        int t = 1;
        for (int i = 2; i <= k; ++ i)
        {
            int r = h % i;
            if (h - r >= l) t = max (t, r);
        }
        h -= t;
        ++ cn;
    }
    cout << cn - 1;
    return;
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