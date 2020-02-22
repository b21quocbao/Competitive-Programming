#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int m, n, ok[mm][mm];
int a[mm][mm];
int hx[3] = {0, 0, 1};
int hy[3] = {1, - 1, 0};

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
    return (x >= 0 && x < m && y >= 0 && y < n);
}

void enter()
{
    cin >> m >> n;
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        cin >> a[i][j];
        a[i][j] /= 100;
    }
    memset (ok, - 1, sizeof (ok));
    priority_queue<pair<int, pair<int, int> > > qu;
    qu.push ({25000, {0, 0}});
    ok[0][0] = 25000;
    while (qu.size())
    {
        int w = qu.top().first;
        int x = qu.top().second.first;
        int y = qu.top().second.second;
        qu.pop();
        if (w != ok[x][y]) continue;
        for (int h = 0; h < 3; ++ h)
        {
            int X = x + hx[h];
            int Y = y + hy[h];
            if (!kt (X, Y)) continue;
            int res;
            if (a[x][y] >= a[X][Y]) res = ok[x][y] - 10;
            else
            {
                res = ok[x][y] - 10 - 4 * (a[X][Y] - a[x][y]) * ((ok[x][y] + 8000) / 1000);
                int l = ok[x][y] / 1000 * 1000 - 1;
                res = max (res, l - 10 - 4 * (a[X][Y] - a[x][y]) * ((l + 8000) / 1000));
            }
            if (res < 0) continue;
            if (ok[X][Y] != - 1 && ok[X][Y] >= res) continue;
            ok[X][Y] = res;
            qu.push ({ok[X][Y], {X, Y}});
        }
    }
    cout << (ok[m - 1][n - 1] == - 1 ? - 1 : ok[m - 1][n - 1]);
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