#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[mm][mm];

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
    for (int i = 1; i <= m; ++ i)
    {
        int x, y;
        cin >> x >> y;
        d[x][y] = 1;
    }
    int sol = 0;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
    for (int i = 1; i * i <= m; ++ i)
    if (m % i == 0)
    {
        int r1 = i, r2 = m / i;
        for (int j = 0; j < 2; ++ j)
        {
            for (int k = 1; k + r1 - 1 <= n; ++ k)
            for (int t = 1; t + r2 - 1 <= n; ++ t)
            sol = max (sol, d[k + r1 - 1][t + r2 - 1] - d[k + r1 - 1][t - 1] - d[k - 1][t + r2 - 1] + d[k - 1][t - 1]);
            swap (r1, r2);
        }
    }
    cout << m - sol;
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