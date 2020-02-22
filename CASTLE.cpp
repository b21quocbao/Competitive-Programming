#include <bits/stdc++.h>

#define fn "test"
#define fn1 "CASTLE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int sol = 0;
int hx[4] = {0, 0, 1, - 1};
bool ok[mm][mm];
int hy[4] = {1, - 1, 0, 0};
pair<int, int>  fa[mm][mm];
int m, n;
int a[mm][mm];

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

bool kt (int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n);
}

pair<int, int> Fa (int x, int y)
{
    return ((fa[x][y].first < 0) ? pair<int, int> (x, y) : fa[x][y] = Fa (fa[x][y].first, fa[x][y].second));
}

void uni (int x, int y, int a, int b)
{
    auto r1 = Fa (x, y);
    auto r2 = Fa (a, b);
    x = r1.first; y = r1.second;
    a = r2.first; b = r2.second;
    if (x == a && y == b) return;
    if (fa[x][y] > fa[a][b])
    {
        swap (a, x);
        swap (b, y);
    }
    fa[x][y].first += fa[a][b].first;
    sol = max (sol, - fa[x][y].first);
    fa[a][b] = {x, y};
}

void enter()
{
    read (m); read (n);
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        char c = getchar();
        while (!isdigit(c)) c = getchar();
        a[i][j] = c - '0';
        fa[i][j] = {- 1, 0};
    }
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    if (!a[i][j])
    for (int h = 0; h < 4; ++ h)
    {
        if (kt (i + hx[h], j + hy[h]))
        if (!a[i + hx[h]][j + hy[h]])
        uni (i, j, i + hx[h], j + hy[h]);
    }
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    if (a[i][j])
    {
        int r = 0;
        vector<pair<int, int> > v; 
        for (int h = 0; h < 4; ++ h)
        {
            int I = i + hx[h], J = j + hy[h];
            if (!kt (I, J)) continue;
            if (a[I][J]) continue;
            auto t = Fa (I, J);
            if (ok[t.first][t.second]) continue;
            ok[t.first][t.second] = 1;
            v.emplace_back(t);
            r += - fa[t.first][t.second].first;
        }
        sol = max (sol, r + 1);
        for (auto i : v)
        ok[i.first][i.second] = 0;
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