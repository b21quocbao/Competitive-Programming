#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "LAND"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long a[mm][mm], c1[mm][mm], c2[mm][mm], r1[mm][mm], r2[mm][mm];
int m, n;
long long t;

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

long long S (int i, int j, int k, int l)
{
    if (k > m || l > n) return t + 1;
    return a[k][l] - a[k][j - 1] - a[i - 1][l] + a[i - 1][j - 1];
}

long long Sq (int i, int j, int t)
{
    if (i + t - 1 > m || j + t - 1 > n) return - 1;
    return S (i, j, i + t - 1, j + t - 1);
}

long long mi (long long a, long long b)
{
    if (!a) return b;
    if (!b) return a;
    return min (a, b);
}

void enter()
{
    int k;
    read (m); read (n); read (k);
    read (t);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        read (a[i][j]);
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
    int sol = 0;
    if (k == 1)
    {
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        {
            while (S (i, j, i + sol, j + sol) <= t)
            ++ sol;
        }
        cout << sol * sol;
    }
    else
    {
        int T = t;
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        for (int t = 1; t <= min (m, n); ++ t)
        {
            auto x = Sq (i, j, t);
            if (x == - 1) break;
            c1[j + t - 1][t] = mi (c1[j + t - 1][t], x);
            r1[i + t - 1][t] = mi (r1[i + t - 1][t], x);
            c2[j][t] = mi (c2[j][t], x);
            r2[i][t] = mi (r2[i][t], x);
        }
        for (int i = 1; i <= m; ++ i)
        for (int t = 1; t <= min (m, n); ++ t)
        r1[i][t] = mi (r1[i][t], r1[i - 1][t]);
        for (int i = m; i >= 1; -- i)
        for (int t = 1; t <= min (m, n); ++ t)
        r2[i][t] = mi (r2[i][t], r2[i + 1][t]);
        for (int i = 1; i <= n; ++ i)
        for (int t = 1; t <= min (m, n); ++ t)
        c1[i][t] = mi (c1[i][t], c1[i - 1][t]);
        for (int i = n; i >= 1; -- i)
        for (int t = 1; t <= min (m, n); ++ t)
        c2[i][t] = mi (c2[i][t], c2[i + 1][t]);
        for (int i = 1; i < m; ++ i)
        for (int t = 1; t <= min (m, n); ++ t)
        for (int t1 = 1; t1 <= min (m, n); ++ t1)
        if (r1[i][t] && r2[i + 1][t1] && (r1[i][t] + r2[i + 1][t1] <= T))
        sol = max (sol, t * t + t1 * t1);
        for (int i = 1; i < n; ++ i)
        for (int t = 1; t <= min (m, n); ++ t)
        for (int t1 = 1; t1 <= min (m, n); ++ t1)
        if (c1[i][t] && c2[i + 1][t1] && c1[i][t] + c2[i + 1][t1] <= T)
        sol = max (sol, t * t + t1 * t1);
        cout << sol;
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