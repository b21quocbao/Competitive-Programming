#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SC"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 5 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int m, n;
int cn[2][mm][mm], d[mm][mm], d2[mm][mm];
int f[mm][mm][2];
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

bool kt (int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}

#define ii pair<int, pair<pair<int, int>, int> >

ii Z (int a, int b, int c, int d)
{
    return (make_pair(a, make_pair (make_pair(b, c), d)));
}

void enter()
{
    read (m); read (n);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        int x;
        read (x);
        while (x % 2 == 0) 
        {
            ++ cn[0][i][j];
            x >>= 1;
        }
        while (x % 5 == 0)
        {
            ++ cn[1][i][j];
            x /= 5;
        }
    }
    priority_queue<ii, vector<ii>, greater<ii> > qu;
    qu.emplace (Z (cn[0][1][1], 1, 1, 0));
    qu.emplace (Z (cn[1][1][1], 1, 1, 1));
    memset (f, 1, sizeof (f));
    f[1][1][0] = cn[0][1][1];
    f[1][1][1] = cn[1][1][1];
    int sol = INT_MAX;
    while (qu.size())
    {
        int x = qu.top().second.first.first, y = qu.top().second.first.second;
        int c1 = qu.top().first, c2 = qu.top().second.second;
        qu.pop();
        if (c1 != f[x][y][c2]) continue;
        if (x == m && y == n)
        {
            sol = min (sol, c1);
            continue;
        }
        for (int h = 0; h < 4; ++ h)
        {
            int X = x + hx[h], Y = y + hy[h], C2 = c2, C1 = c1 + cn[c2][X][Y];
            if (!kt (X, Y)) continue;
            if (f[X][Y][C2] > C1)
            {
                f[X][Y][C2] = C1;
                qu.emplace(Z (C1, X, Y, C2));
            }
        }
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