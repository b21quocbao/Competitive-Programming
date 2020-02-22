#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "PISTOL"

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

int a[mn], b[mn];

void enter()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort (a + 1, a + n + 1);
    sort (b + 1, b + n + 1);
    int m = unique(b + 1, b + n + 1) - b - 1;
    int sol1 = 0, sol2 = 0, sol3 = 0;
    int cn = 0;
    for (int i = 1; i <= m; ++ i)
    {
        int x = upper_bound (b + 1, b + m + 1, k * b[i]) - upper_bound (b + 1, b + m + 1, b[i]);
        sol1 += x * (x - 1) / 2;
    }
    for (int i = 1; i <= n; ++ i)
    {
        ++ cn;
        if (i < n && a[i] == a[i + 1]) continue;
        if (cn >= 3) ++ sol3;
        if (cn >= 2)
        sol2 += upper_bound (b + 1, b + m + 1, a[i] * k) - upper_bound (b + 1, b + m + 1, (a[i] - 1) / k) - 1;
        cn = 0;
    }
    cout << sol1 * 6 + sol2 * 3 + sol3;
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