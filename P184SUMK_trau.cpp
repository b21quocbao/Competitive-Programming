#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 20;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

struct Z
{
    int a, b, c;
};

struct cmp
{
    bool operator () (Z a, Z b)
    {
        if (a.c != b.c)
        return a.c < b.c;
        if (a.a != b.a)
        return a.a < b.a;
        return a.b < b.b;
    }
};

int tt, ntest = 1;
int m, n;
int xs, ys, xt, yt;
multiset<Z, cmp> mu[mn][mn];
int hx[4] = {0, 0, 1, - 1};
bool ok[mn][mn];
int d[mn][mn];
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

int D (int a, int b, int x, int y)
{
    return (a - x) * (a - x) + (b - y) * (b - y);
}

bool kt (int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}

void enter()
{
    read (m); read (n);
    read (xs); read (ys); read (xt); read (yt);
    int k;
    read (k);
    multiset<Z, cmp> qu;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    d[i][j] = INT_MAX;
    for (int i = 0; i < k; ++ i)
    {
        int x, y;
        read (x); read (y);
        d[x][y] = 0;
        // qu.insert ({x, y, 0});
        // mu[x][y].insert ({x, y, 0});
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    for (int x = 1; x <= m; ++ x)
    for (int y = 1; y <= n; ++ y)
    if (!d[x][y])
    d[i][j] = min (d[i][j], D (i, j, x, y));
    // while (qu.size())
    // {
    //     int x = qu.begin()->a, y = qu.begin()->b;
    //     d[x][y] = qu.begin()->c;
    //     qu.erase (qu.begin());
    //     for (int h = 0; h < 4; ++ h)
    //     {
    //         int X = x + hx[h], Y = y + hy[h];
    //         if (!kt (X, Y)) continue;
    //         for (auto r : mu[x][y])
    //         {
    //             int re = 2 * (int)(1e9) + 1;
    //             if (mu[X][Y].size()) re = mu[X][Y].begin()->c;
    //             if (mu[X][Y].size() < mm)
    //             mu[X][Y].insert ({r.a, r.b, D (r.a, r.b, X, Y)});
    //             else if (D (r.a, r.b, x, y) < mu[x][y].rbegin()->c)
    //             {
    //                 mu[X][Y].erase( next(mu[X][Y].rbegin()).base() );
    //                 mu[X][Y].insert({r.a, r.b, D (r.a, r.b, x, y)});
    //             }
    //             if (mu[X][Y].size() && (mu[X][Y].begin()->c < re))
    //             {
    //                 if (re != 2 * (int)(1e9) + 1) qu.erase ({X, Y, re});
    //                 qu.insert ({X, Y, mu[X][Y].begin()->c});
    //             }
    //         }
    //     }
    // }
    
    int inf = 0, sup = min (d[xs][ys], d[xt][yt]), sol;
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        queue<pair<int, int> > qu;
        qu.push ({xs, ys});
        memset (ok, 0, sizeof (ok));
        ok[xs][ys] = 1;
        while (qu.size())
        {
            int x = qu.front().first, y = qu.front().second;
            qu.pop();
            for (int h = 0; h < 4; ++ h)
            {
                int X = x + hx[h], Y = y + hy[h];
                if (!kt (X, Y)) continue;
                if (d[X][Y] < mid) continue;
                if (ok[X][Y]) continue;
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