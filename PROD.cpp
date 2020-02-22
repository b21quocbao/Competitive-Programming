#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PROD"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[12][12][12][12][6];
int sol = INT_MIN;
int a[12][12];
int l;

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

void Cnh (int& sol, int x, int y)
{
    if (x == l || y == l) return;
    sol = max (sol, x * y);
}

void cnh (int f[6], int x)
{
    if (x > 0)
    {
        if (f[0] == l || x > f[0])
        {
            f[1] = f[0];
            f[0] = x;
        }
        else if (f[1] == l || x > f[1])
        f[1] = x;
        if (f[4] == l || x < f[4])
        f[4] = x;
    }
    else if (x < 0)
    {
        if (f[2] == l || x < f[2])
        {
            f[3] = f[2];
            f[2] = x;
        }
        else if (f[3] == l || x < f[3])
        f[3] = x;
        if (f[5] == l || x > f[5])
        f[5] = x; 
    }
    Cnh (sol, f[0], f[1]);
    Cnh (sol, f[2], f[3]);
    Cnh (sol, f[4], f[5]);
}

void enter()
{
    int k, m, n;
    read (k); read (m); read (n);
    memset (f, 1, sizeof (f));
    l = f[0][0][0][0][0];
    for (int t = 1; t <= k; ++ t)
    {
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        read (a[i][j]);
        for (int x = 1; x <= m; ++ x)
        for (int u = x + 1; u <= m; ++ u)
        for (int y = 1; y <= m; ++ y)
        for (int v = y + 1; v <= n; ++ v)
        cnh (f[x][y][u][v], a[x][y] * a[x][v] * a[u][y] * a[u][v]);
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