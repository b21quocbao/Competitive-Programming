#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
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

#define y1 __y1

struct Z
{
    int x1, y1, x2, y2;
    Z (){}
    Z (int X1, int Y1, int X2, int Y2)
    {
        x1 = X1; y1 = Y1; x2 = X2; y2 = Y2;
    }
};
vector<Z> v;
int miX = INT_MAX, miY = INT_MAX, maX = INT_MIN, maY = INT_MIN;
vector<vector<int> > d;
int hx[4] = {0, 0, 1, - 1}, hy[4] = {1, - 1, 0, 0};
vector<vector<int> > a;
pair<int, int> s, t;
int n, m;

void Cd (int x1, int y1, int x2, int y2)
{
    x1 = max (x1, 0);
    x2 = min (x2, m + n - 2);
    y1 = max (y1, 0 - (n - 1));
    y2 = min (y2, m - 1);
    miX = min (miX, x1);
    miY = min (miY, y1);
    maX = max (maX, x2);
    maY = max (maY, y2);
    v.emplace_back(x1, y1, x2, y2);
}

void Pre()
{
    a.resize(maX - miX + 3, vector<int>(maY - miY + 3));
    for (auto i : v)
    {
        ++ a[i.x1 - miX][i.y1 - miY];
        -- a[i.x1 - miX][i.y2 - miY + 1];
        -- a[i.x2 - miX + 1][i.y1 - miY];
        ++ a[i.x2 - miX + 1][i.y2 - miY + 1];
    }
    for (int i = miX; i <= maX; ++ i)
    for (int j = miY; j <= maY; ++ j)
    a[i - miX][j - miY] += (i == miX ? 0 : a[i - miX - 1][j - miY]);
    for (int i = miX; i <= maX; ++ i)
    for (int j = miY; j <= maY; ++ j)
    a[i - miX][j - miY] += (j == miY ? 0 : a[i - miX][j - miY - 1]);
}


void enter()
{
    int d;
    cin >> n >> m >> d;
    cin.ignore();
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < m; ++ j)
    {
        char c;
        cin >> c;
        if (c == 'M')
        Cd (j + i - d, j - i - d, j + i + d, j - i + d);
        else if (c == 'S')
        s = {i, j};
        else if (c == 'F')
        t = {i, j};
    }   
}


bool invalid (int U, int V)
{
    int x = U + V, b = V - U;
    return (x >= miX && x <= maX && b >= miY && b <= maY && a[x - miX][b - miY]);
}

void Bfs (int u, int v)
{
    queue<pair<int, int> > qu;
    qu.emplace(u, v);
    while (qu.size())
    {
        int u = qu.front().first, v = qu.front().second;
        qu.pop();
        for (int h = 0; h < 4; ++ h)
        {
            int U = u + hx[h];
            int V = v + hy[h];
            if (U >= n || U < 0 || V >= m || V < 0) continue;
            if (d[U][V]) continue;
            if (invalid(U, V)) continue;
            d[U][V] = d[u][v] + 1;
            qu.emplace(U, V);
        }
    }
}

void solve()
{
    Pre();
    d.resize(n, vector<int> (m));
    if (invalid(s.first, s.second)) return;
    d[s.first][s.second] = 1;
    Bfs (s.first, s.second);
}

void print_result()
{
    cout << d[t.first][t.second] - 1;
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