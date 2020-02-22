#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LABIRINT"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 30 + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
struct Z   
{
    int x, y, c, hg;
    Z (){}
    Z (int X, int Y, int C, int Hg)
    {
        x = X; y = Y; c = C; hg = Hg;
    }
};
int k, m, n;
int a[mm][mm];
int ok[mm][mm][mm][4];
Z tr[mm][mm][mm][4];
int hx[4][3] = {{- 1, 0, 0}, {- 1, 0, 1}, {0, 1, 0}, {- 1, 1, 0}};
int hy[4][3] = {{0, 1, - 1}, {0, 1, 0}, {1, 0, - 1}, {0, 0, - 1}};
int hu[4][3] = {{0, 1, 3}, {0, 1, 2}, {1, 2, 3}, {0, 2, 3}};
int cn[4][3] = {{0, 1, 0}, {0, 0, 1}, {0, 0, 1}, {1, 0, 0}};

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

inline bool kt (int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n);
}

void enter()
{
    cin >> k >> m >> n;
    pair<int, int> s, t;
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        cin >> a[i][j];
        if (a[i][j] == 2)
        s = {i, j};
        else if (a[i][j] == 3)
        t = {i, j};
    }
    queue<Z> qu;
    for (int h = 0; h < 4; ++ h)
    {
        qu.emplace(s.first, s.second, 0, h);
        ok[s.first][s.second][0][h] = 1;
    }
    while  (qu.size())
    {
        int x = qu.front().x, y = qu.front().y;
        int c = qu.front().c, hg = qu.front().hg;
        qu.pop();
        if (t == make_pair(x, y))
        {
            cout << ok[x][y][c][hg] - 1 << "\n";
            return;
        }
        for (int h = 0; h < 3; ++ h)
        {
            int X = x + hx[hg][h]; int Y = y + hy[hg][h];
            int Hg = hu[hg][h], C = c + cn[hg][h];
            if (C > k) continue;
            if (!kt (X, Y)) continue;
            if (a[X][Y] == 1) continue;
            if (ok[X][Y][C][Hg]) continue;
            ok[X][Y][C][Hg] = ok[x][y][c][hg] + 1;
            qu.emplace(X, Y, C, Hg);
        }
    }
    cout << - 1;
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