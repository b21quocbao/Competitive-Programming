#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e4) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int fa[mn], m, n;
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
int a[mm][mm];
int te = 0;
int d[1010];
int ok[mm][mm], ok1[mm][mm];

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

bool kt (int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}

bool kt2 (int x, int y)
{
    return (x >= 0 && x <= m + 1 && y >= 0 && y <= n + 1);
}

void dfs (int x, int y, int h, int& r)
{
    for (int hg = 0; hg < 4; ++ hg)
    {
        int X = x + hx[hg], Y = y + hy[hg];
        if (!kt2 (X, Y)) continue;
        if (kt (X, Y) && ok[X][Y]) continue;
        if (kt (X, Y) && a[x][y] >= h && a[X][Y] < h) continue;
        if (!kt (X, Y) && ok[X][Y] == te) continue;
        if (!kt (x, y) && a[X][Y] >= h) continue;
        if (kt (x, y) && a[x][y] >= h && a[x][y] > a[X][Y]) continue;
        if (kt (x, y) && a[X][Y] >= h && ok1[X][Y]) continue;
        ok[X][Y] = te;
        if (kt (X, Y))
        {
            if (a[X][Y] >= h) 
            {
                ok1[X][Y] = 1;
                ok[X][Y] = 0;
                -- d[a[X][Y]];
            }
            if (a[X][Y] < h && !ok1[X][Y]) -- r;
        }  
        dfs (X, Y, h, r);
    }
}

void enter()
{   
    cin >> m >> n;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> a[i][j];
        ++ d[a[i][j]];
    }
    int sol = 0;
    memset (fa, - 1, sizeof (fa));
    int r = 0;
    for (int h = 1; h <= 1000; ++ h)
    {
        r += d[h - 1];
        ++ te;
        dfs (0, 0, h, r);
        sol += r;
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