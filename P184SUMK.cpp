#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int m, n, xs, ys, xt, yt;
int d[mn][mn], a[mn][mn];
bool ok[mn][mn];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};

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

int kt (int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}

void enter()
{
    read (m); read (n);
    read (xs); read (ys); read (xt); read (yt);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    d[i][j] = 10000;
    int k;
    read (k); 
    for (int i = 0; i < k; ++ i)
    {
        int x, y;
        read (x); read (y);
        d[x][y] = 0;
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 2; j <= n; ++ j)
    d[i][j] = min (d[i][j - 1] + 1, d[i][j]);
    for (int i = 1; i <= m; ++ i)
    for (int j = n - 1; j >= 1; -- j)
    d[i][j] = min (d[i][j + 1] + 1, d[i][j]);
    int inf = 0, sup = m * m + n * n, sol;
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        memset (a, 0, sizeof (a));
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        {
            int c = mid - d[i][j] * d[i][j];
            if (c < 0) continue;
            int r = (trunc(sqrt (c)));
            int x = max (i - r + (r * r == c ? 1 : 0), 1);
            int y = min (i + r - (r * r == c ? 1 : 0), m);
            if (y < x) continue;
            ++ a[x][j];
            -- a[y + 1][j];
        }
        for (int j = 1; j <= n; ++ j)
        for (int i = 1; i <= m; ++ i)
        a[i][j] += a[i - 1][j];
        queue<pair<int, int> > qu;
        memset (ok, 0, sizeof (ok));
        if (!a[xs][ys])
        {
            qu.push ({xs, ys});
            ok[xs][ys] = 1;
        }
        while (qu.size())
        {
            if (ok[xt][yt]) break;
            int x = qu.front().first, y = qu.front().second;
            qu.pop();
            for (int h = 0; h < 4; ++ h)
            {
                int X = x + hx[h], Y = y + hy[h];
                if (!kt (X, Y) || (a[X][Y] || ok[X][Y])) continue;
                ok[X][Y] = 1;
                qu.push ({X, Y});
            }
        }
        if (ok[xt][yt])
        {
            sol = mid;
            inf = mid + 1;
        }
        else sup = mid - 1;
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