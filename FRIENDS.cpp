#include <bits/stdc++.h>

#define fn "test"
#define fn1 "FRIENDS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, a, b, x[mm][mm], d[mm][mm];

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
    read (n); read (a); read (b);
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    read (x[i][j]);
    int inf = a * b, sup = n * n, sol;
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
        if (x[i][j] <= mid) d[i][j] = 1;
        else d[i][j] = 0;
        for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
        d[i][j] += d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1];
        bool ok = 0;
        for (int i = 1; i + a - 1 <= n; ++ i)
        for (int j = 1; j + b - 1 <= n; ++ j)
        if (d[i + a - 1][j + b - 1] - d[i - 1][j + b - 1] - d[i + a - 1][j - 1] + d[i - 1][j - 1] == a * b)
        ok = 1;
        for (int i = 1; i + b - 1 <= n; ++ i)
        for (int j = 1; j + a - 1 <= n; ++ j)
        if (d[i + b - 1][j + a - 1] - d[i - 1][j + a - 1] - d[i + b - 1][j - 1] + d[i - 1][j - 1] == a * b)
        ok = 1;
        if (ok)
        {
            sol = mid;
            sup = mid - 1;
        }
        else inf = mid + 1;
    }
    cout << sol;
}

void solve()
{

}

void print_result()
{

}

int main()
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