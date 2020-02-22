#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LILYPAD"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 33;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int m, n;
int fa[mm * mm];
int a[mm][mm];
int hx[8] = {1, 1, - 1, - 1, 2, 2, - 2, - 2};
int hy[8] = {2, - 2, 2, - 2, 1, - 1, 1, - 1};
int Num[mm * mm];
vector<pair<int, int> > v[mm * mm], e[mm][mm];
bool ok[mm][mm][mm][mm];
int d[mm][mm];
long long l[mm][mm];

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

int Id (int x, int y)
{
    return (x - 1) * n + y;
}

int Fa (int x)
{
    return (fa[x] < 0 ? x : fa[x] = Fa (fa[x]));
}

void uni (int a, int b, int x, int y)
{
    int u = Id (a, b), v = Id (x, y);
    u = Fa (u), v = Fa (v);
    if (u == v) return;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
}

void enter()
{
    cin >> m >> n;
    memset (fa, - 1, sizeof (fa));
    pair<int, int> s, t;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> a[i][j];
        if (a[i][j] == 3)
        {
            s = {i, j};
            a[i][j] = 0;
        }
        else if (a[i][j] == 4)
        {
            t = {i, j};
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    if (a[i][j] == 1)
    for (int h = 0; h < 8; ++ h)
    {
        int x = i + hx[h], y = j + hy[h];
        if (!kt (x, y)) continue;
        if (!a[x][y]) continue;
        if (a[x][y] == 2) continue;
        uni (i, j, x, y);
    }
    int NNum = 0;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    if (a[i][j] == 1)
    {
        if (!Num[Fa (Id (i, j))])
        Num[Fa (Id (i, j))] = ++ NNum;
        int r = Num[Fa (Id (i, j))];
        for (int h = 0; h < 8; ++ h)
        {
            int x = i + hx[h], y = j + hy[h];
            if (!kt (x, y)) continue;
            if (a[x][y]) continue;
            v[r].emplace_back(x, y);
        }
    }
    for (int i = 1; i <= NNum; ++ i)
    {
        sort(v[i].begin(), v[i].end());
        v[i].resize(unique (v[i].begin(), v[i].end()) - v[i].begin());
        for (auto k : v[i])
        for (auto t : v[i])
        if (k != t)
        if (!ok[k.first][k.second][t.first][t.second])
        {
            ok[k.first][k.second][t.first][t.second] = 1;   
            e[k.first][k.second].emplace_back(t);
        }
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    if (!a[i][j])
    for (int h = 0; h < 8; ++ h)
    {
        int x = i + hx[h], y = j + hy[h];
        if (!kt (x, y)) continue;
        if (a[x][y]) continue;
        if (ok[i][j][x][y]) continue;
        ok[i][j][x][y] = 1;
        e[i][j].emplace_back(x, y);
    }
    queue<pair<int, int> > qu;
    qu.emplace(s);
    d[s.first][s.second] = 1;
    l[s.first][s.second] = 1;
    while (qu.size())
    {
        int x = qu.front().first, y = qu.front().second;
        qu.pop();
        for (auto u : e[x][y])
        {
            int X = u.first, Y = u.second;
            if (!kt (X, Y)) continue;
            if (d[X][Y]) 
            {
                if (d[X][Y] == d[x][y] + 1)
                l[X][Y] += l[x][y]; 
                continue;
            }
            d[X][Y] = d[x][y] + 1;
            l[X][Y] = l[x][y];
            qu.emplace(X, Y);
        }
    }
    if (!d[t.first][t.second])
    {
        cout << - 1;
        return;
    }
    cout << d[t.first][t.second] - 2 << "\n";
    cout << l[t.first][t.second];
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