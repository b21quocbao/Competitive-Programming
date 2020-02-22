#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DMS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[110][510];
int a[110];

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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    memset (f, - 1, sizeof (f));
    f[0][m] = 1;
    for (int i = 1; i <= n; ++ i)
    for (int j = 0; j <= m; ++ j)
    for (int k = j + a[i]; k <= m; k += a[i])
    if (f[i - 1][k] != - 1)
    {
        if (f[i][j] == - 1) f[i][j] = 0;
        f[i][j] += f[i - 1][k];
        if (f[i][j] >= mod) f[i][j] -= mod;
    }
    cout << f[n][0];
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