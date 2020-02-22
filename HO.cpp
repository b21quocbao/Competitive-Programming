#include <bits/stdc++.h>

#define fn "test"
#define fn1 "HO"

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

int f[2010][2010], g[2010][2010];

void enter()
{
    int  M, N, X;
    cin >> M >> N;
    int m, n;
    read (m); read (n);
    int sol = 0;
    int x;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        read (x);
        if (x)
        {
            f[i][j] = f[i - 1][j] + 1;
            g[i][j] = 0;
        }
        else
        {
            f[i][j] = 0;
            g[i][j] = g[i - 1][j] + 1;
        }
    }
    for (int i = 2; i < m; ++ i)
    for (int j = 2, cur = - 1, I, J = - 1; j < n; ++ j)
    {
        if (f[i + 1][j]) J = j;
        if (f[i][j] != cur)
        {
            cur = f[i][j];
            I = j;
        }
        if (g[i + 1][j + 1] >= cur + 2 && g[i + 1][I - 1] >= cur + 2 && J < I && cur < i)
        sol = max (sol, cur * (j - I + 1));
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
