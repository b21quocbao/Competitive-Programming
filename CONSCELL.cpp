#include <bits/stdc++.h>

#define fn "test"
#define fn1 "CONSCELL"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
int a[mm][mm], m, n, f[mm][mm];

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
bool read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    int cn = 0;
    while (!isdigit(ch)) 
    {
        f = ch == '-' ? - f : f, ch = getchar();
        if (++ cn == 5) return 0;
    }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
    return 1;
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
    vector<pair<int, int> > id;
    if (!read (m)) exit (0);
    read (n);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        read (a[i][j]);
        id.emplace_back(i, j);
    }
    sort (id.begin(), id.end(), [](pair<int, int>  i, pair<int, int>  j)
         {
             return a[i.first][i.second] < a[j.first][j.second]; 
         });
    memset (f, 0, sizeof (f));
    int sol = 0;
    for (auto k : id)
    {
        int x = k.first, y = k.second;
        if (!f[x][y]) f[x][y] = 1;
        sol = max (sol, f[x][y]);
        for (int hg = 0; hg < 4; ++ hg)
        {
            int X = x + hx[hg], Y = y + hy[hg];
            if (!kt (X, Y)) continue;
            if (a[X][Y] == a[x][y] + 1)
            f[X][Y] = max (f[X][Y], f[x][y] + 1);
        }
    }
    write (sol);
    putchar ('\n');
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
    // read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}