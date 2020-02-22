#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
int m, n, nq, np, nk;
pair<int, int> q[mm];
int hx[8] = {1, 1, - 1, - 1, 2, 2, - 2, - 2};
int hy[8] = {2, - 2, 2, - 2, 1, - 1, 1, - 1};
bool ok[mm][mm], p[mm][mm];

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

void enter()
{
    cin >> m >> n;
    if (!m && !n) exit (0);
    cin >> nq;
    for (int i = 0; i < nq; ++ i)
    cin >> q[i].first >> q[i].second;
    cin >> nk;
    int sol = 0;
    memset (ok, 0, sizeof (ok));
    memset (p, 0, sizeof (p));
    for (int i = 0; i < nk; ++ i)
    {
        int x, y;
        cin >> x >> y;
        if (!ok[x][y]) ++ sol;
        ok[x][y] = 1;
        p[x][y] = 1;
        for (int j = 0; j < 8; ++ j)
        {
            int X = x + hx[j], Y = y + hy[j];
            if (!kt (X, Y)) continue;
            if (!ok[X][Y]) ++ sol;
            ok[X][Y] = 1;
        }
    }
    cin >> np;
    for (int i = 0; i < np; ++ i)
    {
        int x, y;
        cin >> x >> y;
        if (!ok[x][y]) ++ sol;
        ok[x][y] = 1;
        p[x][y] = 1;
    }
    for (int i = 0; i < nq; ++ i)
    {
        for (int j = q[i].second - 1; j >= 1; -- j)
        if (p[q[i].first][j]) break;
        else
        {
            if (!ok[q[i].first][j]) ++ sol;
            ok[q[i].first][j] = 1;
        }
        for (int j = q[i].second; j <= n; ++ j)
        if (p[q[i].first][j]) break;
        else
        {
            if (!ok[q[i].first][j]) ++ sol;
            ok[q[i].first][j] = 1;
        }
        for (int j = q[i].first - 1; j >= 1; -- j)
        if (p[j][q[i].second]) break;
        else
        {
            if (!ok[j][q[i].second]) ++ sol;
            ok[j][q[i].second] = 1;
        }
        for (int j = q[i].first; j <= m; ++ j)
        if (p[j][q[i].second]) break;
        else
        {
            if (!ok[j][q[i].second]) ++ sol;
            ok[j][q[i].second] = 1;
        }
        for (int x = q[i].first, y = q[i].second; x >= 1 && y >= 1; -- x, -- y)
        if (p[x][y]) break;
        else
        {
            if (!ok[x][y]) ++ sol;
            ok[x][y] = 1;
        }
        for (int x = q[i].first, y = q[i].second; x <= m && y <= n; ++ x, ++ y)
        if (p[x][y]) break;
        else
        {
            if (!ok[x][y]) ++ sol;
            ok[x][y] = 1;
        }
        for (int x = q[i].first, y = q[i].second; x >= 1 && y <= n; -- x, ++ y)
        if (p[x][y]) break;
        else
        {
            if (!ok[x][y]) ++ sol;
            ok[x][y] = 1;
        }
        for (int x = q[i].first, y = q[i].second; x <= m && y >= 1; ++ x, -- y)
        if (p[x][y]) break;
        else
        {
            if (!ok[x][y]) ++ sol;
            ok[x][y] = 1;
        }
        p[q[i].first][q[i].second] = 1;

    }
    cout << "Board " << tt << " has " << m * n - sol << " safe squares.\n";
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