#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
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

int n, m, t[mn], x[mn];

void enter()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    cin >> t[i];
    for (int i = 1; i <= m; ++ i)
    cin >> x[i];
    long long sol = 0;
    if (x[1] <= t[1]) sol += 2 * abs (t[1] - x[1]);
    for (int i = 2; i <= n; ++ i)
    {
        int vt1 = lower_bound(x + 1, x + m + 1, t[i - 1]) - x;
        int vt2 = lower_bound (x + 1, x + m + 1, t[i]) - x;
        if (vt1 == vt2) continue;
        int s = t[i] - t[i - 1];
        int mi = s;
        mi = min (mi, 2 * (x[vt2 - 1] - t[i - 1]));
        mi = min (mi, 2 * (t[i] - x[vt1]));
        for (int j = vt1; j < vt2 - 1; ++ j)
        mi = min (mi, 2 * (x[j] - t[i - 1]) + 2 * (t[i] - x[j + 1]));
        sol += mi;
    }
    if (x[m] >= t[n]) sol += 2 * (x[m] - t[n]);
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