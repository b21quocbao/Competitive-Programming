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
int ok[mm][mm], m, n;
int hx[8] = {- 2, - 2, - 1, - 1, 1, 1, 2, 2};
int hy[8] = {1, - 1, 2, - 2, 2, - 2, 1, - 1};

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
    memset (ok, -1, sizeof (ok));
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    queue<pair<int, int> > qu;
    qu.push ({x1, y1});
    ok[x1][y1] = 0;
    while (qu.size())
    {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        for (int h = 0; h < 8; ++ h)
        {
            int X = x + hx[h];
            int Y = y + hy[h];
            if (!kt (X, Y)) continue;
            if (ok[X][Y] != - 1) continue;
            ok[X][Y] = ok[x][y] + 1;
            qu.push ({X, Y});
        }
    }
    cout << ok[x2][y2];
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