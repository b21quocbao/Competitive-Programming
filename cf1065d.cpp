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
int n;
pair<int, int> f[110][110][3][2];
int hx[8] = {2, 2, 1, 1, - 1, - 1, - 2, - 2};
int hy[8] = {1, - 1, 2, - 2, 2, - 2, 1, - 1};
pair<int, int> vt[110];
int a[20][20];

struct Z
{
    int k, x, y, ok;
    Z (){}
    Z (int _k, int _x, int _y, int _ok)
    {
        k = _k; x = _x;
        y = _y; ok = _ok;
    }
};


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
    return (x >= 0 && x < n && y >= 0 && y < n);
}

#define ii pair<int, int>  

struct cmp
{
    bool operator () (pair<ii, Z> a, pair<ii, Z> b)
    {
        return a.first < b.first;
    }
};


void F ()
{
    priority_queue<pair<ii, Z>, vector<pair<ii, Z> >, cmp> qu;
    qu.emplace(0, 0, 1, 1, 0, 0);
    qu.emplace(0, 0, 1, 1, 1, 0);
    qu.emplace(0, 0, 1, 1, 2, 0);
    f[1][1][0][0] = f[1][1][1][0] = f[1][1][2][0] = {0, 0};
    while (qu.size())
    {
        auto R = qu.top().first;
        int k = qu.top().second.k;
        int x = qu.top().second.x;
        int y = qu.top().second.y;
        int ok = qu.top().second.ok;
        qu.pop();
        if (R != f[k][x][y][ok]) continue;
        if (k = n * n)
        {
            cout << R.first << " " << R.second;
            return;
        }
        if (!ok)
        {
            for (int i = 0; i < 3; ++ i)
            if (i != y)
            {
                auto r = R;
                ++ r.second; ++ r.first;
                if (f[k][x][i][ok].first == - 1 || f[k][x][i][ok] > r)
                {
                    f[k][x][i][ok] = r;
                    qu.emplace (r, Z (k, x, i, ok));
                }
            }
        }
        if (!y)
        {
            for (int i = 0; i < n; ++ i)
            if (i != vt[x].second)
            {
                auto r = R;
                ++ r.first;
                if (a[vt[x].first][i] != k + 1)
                {
                    if (f[k][a[vt[x].first][i]][y][ok].first == - 1)
                    // if (f[k][a[vt[x].first][i]][y][ok].first == - 1 || f[k][a[vt[x].first][i]][y][ok] > r)
                    {
                        f[k][a[vt[x].first][i]][y][ok] = r;
                        qu.emplace (r, Z (k, a[vt[x].first][i], i, ok));
                    }
                }
                else
                {
                    if (f[k + 1][k + 1][y][ok].first == - 1 || f[k + 1][k + 1][y][ok] > r)
                    {
                        f[k + 1][k + 1][y][ok] = r;
                        qu.emplace (r, Z (k + 1, k + 1, y, ok));
                    }
                }
            }
            for (int i = 0; i < n; ++ i)
            if (i != vt[x].first)
            {
                auto r = R;
                ++ r.first;
                if (a[i][vt[x].second] != k + 1)
                {
                    if (f[k][i][a[vt[x].second]][ok].first == - 1 || f[k][i][a[vt[x].second]][ok] > r)
                    {
                        f[k][i][a[vt[x].second]][ok] = r;
                        qu.emplace (r, Z (k, a[vt[x].first], i, ok));
                    }
                }
                else
                {
                    if (f[k + 1][k + 1][y][ok].first == - 1 || f[k + 1][k + 1][y][ok] > r)
                    {
                        f[k + 1][k + 1][y][ok] = r;
                        qu.emplace (r, Z (k + 1, k + 1, y, ok));
                    }
                }
            }
        }
        else if (y == 1)
        {
            for (int i = - n; i <= n; ++ i)
            {
                pair<int, int> r;
                int X = vt[x].first + i;
                int Y = vt[x].second + i;
                if (!i) continue;
                if (!kt (X, Y)) continue;
                auto r = R;
                ++ r.first;
                if (a[X][Y] == k + 1)
                {
                    if (f[k + 1][k + 1][y][ok].first == - 1 || f[k + 1][k + 1][y][ok] > r)
                    {
                        f[k + 1][k + 1][y][ok] = r;
                        qu.emplace (r, Z (k + 1, k + 1, y, ok));
                    }
                }
                else
                {
                    if (f[k][X][Y][ok].first == - 1 || f[k][X][Y][ok] > r)
                    {
                        f[k][X][Y][ok] = r;
                        qu.emplace (r, Z (k, X, Y, ok));
                    }
                }
            }
            for (int i = - n; i <= n; ++ i)
            {
                pair<int, int> r;
                int X = vt[x].first - i;
                int Y = vt[x].second + i;
                if (!i) continue;
                if (!kt (X, Y)) continue;
                auto r = R;
                ++ r.first;
                if (a[X][Y] == k + 1)
                {
                    if (f[k + 1][k + 1][y][ok].first == - 1 || f[k + 1][k + 1][y][ok] > r)
                    {
                        f[k + 1][k + 1][y][ok] = r;
                        qu.emplace (r, Z (k + 1, k + 1, y, ok));
                    }
                }
                else
                {
                    if (f[k][X][Y][ok].first == - 1 || f[k][X][Y][ok] > r)
                    {
                        f[k][X][Y][ok] = r;
                        qu.emplace (make_pair(r, Z (k, X, Y, ok)));
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < 8; ++ i)
            {
                pair<int, int> r;
                int X = vt[x].first + hx[i];
                int Y = vt[x].second + hy[i];
                if (!kt (X, Y)) continue;
                auto r = R;
                ++ r.first;
                if (a[X][Y] == k + 1)
                {
                    if (f[k + 1][k + 1][y][ok].first == - 1 || f[k + 1][k + 1][y][ok] > r)
                    {
                        f[k + 1][k + 1][y][ok] = r;
                        qu.emplace (make_pair(r, Z (k + 1, k + 1, y, ok)));
                    }
                }
                else
                {
                    if (f[k][X][Y][ok].first == - 1 || f[k][X][Y][ok] > r)
                    {
                        f[k][X][Y][ok] = r;
                        qu.emplace (r, Z (k, X, Y, ok));
                    }
                }
            }
        }
    }
}

void enter()
{
    cin >> n;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        int x;
        cin >> x;
        a[i][j] = x;
        vt[x] = {i, j};
    }
    pair<int, int> sol;
    sol.first = (int)(1e8);
    memset (f, - 1, sizeof (f));
    F ();

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