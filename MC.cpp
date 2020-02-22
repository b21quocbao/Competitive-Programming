#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MC"

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

int n, m, Ke;
int kc[310][310];
const int& de = 1;


inline int C (const int& x, const int& y, const int& v)
{
    return 0 * kc[x][y] + v * de;
}


struct Z
{
    int x, y, k, hg;
    Z () {}
    Z (const int& X, const int& Y, const int& K, const int& Hg)
    {
        x = X; y = Y; k = K; hg = Hg;
    }
};


int a[310][310], b[310][310];
int hx[4][4] = {{0, 0, 1, - 1}, {0, 0, - 1, 1}, {1, - 1, 0, 0}, {- 1, 1, 0, 0}};
int hy[4][4] = {{1, - 1, 0, 0}, {- 1, 1, 0, 0}, {0, 0, - 1, 1}, {0, 0, 1, - 1}};
int H[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 1, 0}, {3, 2, 0, 1}};
int D[4][4] = {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}};
int d[310][310][32][4];
int e[310][310][32][4];
int ok[310][310][32][4];

int sol = INT_MAX;

void dijkstra()
{
    deque<Z> qu;
    qu.emplace_back (1, 1, 0, 0);
    qu.emplace_back (1, 1, 0, 2);
    memset (d, - 1, sizeof (d));
    memset (ok, 0, sizeof (ok));
    d[1][1][0][0] = C (1, 1, a[1][1]);
    e[1][1][0][0] = a[1][1];
    d[1][1][0][2] = C (1, 1, a[1][1]);
    e[1][1][0][2] = a[1][1];
    ok[1][1][0][0] = 1;
    ok[1][1][0][2] = 1;
    while (qu.size())
    {
        int x = qu.front().x, y = qu.front().y, k = qu.front().k;
        int hg = qu.front().hg, r = d[x][y][k][hg], v = e[x][y][k][hg];
        qu.pop_front();
        ok[x][y][k][hg] = 2;
        if (r >= sol) continue;
        for (int h = 0; h < 4; ++ h)
        {
            int X = x + hx[hg][h], Y = y + hy[hg][h], K = k + D[hg][h];
            int V = v + a[X][Y], Hg = H[hg][h], R = C (X, Y, V);
            if (X <= 0 || X > m) continue;
            if (Y <= 0 || Y > n) continue;
            if (K > Ke) continue;
            if (d[X][Y][K][Hg] != - 1 && d[X][Y][K][Hg] <= R) continue;
            if (X == m && Y == 1) 
            {
                sol = min (sol, R);
                continue;
            }
            if (ok[X][Y][K][Hg] == 2)
            qu.emplace_front (X, Y, K, Hg);
            if (!ok[X][Y][K][Hg])
            qu.emplace_back (X, Y, K, Hg);
            ok[X][Y][K][Hg] = 1;
            d[X][Y][K][Hg] = R;
            e[X][Y][K][Hg] = V;
        }
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    for (int l = 0; l <= Ke; ++ l)
    for (int t = 0; t < 4; ++ t)
    if (ok[i][j][l][t] == 1)
    cerr << "dmm\n";
}

void enter()
{
    read (m); read (n); read (Ke);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        int x;
        read (x);
        while (x % 2 == 0)
        {
            ++ b[i][j];
            x /= 2;
        }
        while (x % 5 == 0)
        {
            ++ a[i][j];
            x /= 5;
        }
        kc[i][j] = m - i + j - 1;
    }
    dijkstra();
    swap (a, b);
    dijkstra();
    cout << sol / de;
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