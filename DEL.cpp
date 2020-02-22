#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DEL"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 3 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, a[mn];
int f[mm][mm];

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    f[i][j] = (j - i + 1);
    for (int l = 2; l <= n; ++ l)
    for (int i = 1; i <= n; ++ i)
    {
        int j = i + l - 1;
        f[i][j] = min (f[i][j], f[i + 1][j] + 1);
        f[i][j] = min (f[i][j], f[i][j - 1] + 1);
        for (int k = i + 1; k <= j; ++ k)
        {
            if (a[i] == a[k])
            f[i][j] = min (f[i][j], f[i + 1][k] + f[k + 1][j]);
            if (a[j] == a[k - 1])
            f[i][j] = min (f[i][j], f[i][k - 1] + f[k][j - 1]);
        }
    }
    cout << f[1][n];
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