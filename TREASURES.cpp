#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TREASURES"

using namespace std;

const int mn = 7 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
string s[mn];
bool vl[mn][mn];
int m, n;
int d[mn][mn];
pair<int, int> Cb, Di, Xp;
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
int Row[mn][mn], Col[mn][mn], CampRow[mn][mn], CampCol[mn][mn];

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
    return (x >= 0 && x < m && y >= 0 && y < n);
}

void Bfs (pair<int, int> x)
{
    queue<pair<int, int> > qu;
    qu.emplace(x);
    d[x.first][x.second] = 1;
    while (qu.size())
    {
        int x = qu.front().first, 
        y = qu.front().second;  
        qu.pop();
        if (d[x][y] != 1)
        {
            if (!CampRow[Row[x][y]][y])
            CampRow[Row[x][y]][y] = d[x][y];
            if (!CampCol[x][Col[x][y]])
            CampCol[x][Col[x][y]] = d[x][y];
        }
        for (int h = 0; h < 4; ++ h)
        {
            int X = x + hx[h], Y = y + hy[h];
            if (!kt (X, Y)) continue;
            if (d[X][Y]) continue;
            if (vl[X][Y]) continue;
            d[X][Y] = d[x][y] + 1;
            qu.emplace (X, Y);
        }
    }
}

void UniRow ()
{
    for (int j = 0; j < n; ++ j)
    {
        int cn = 0;
        for (int i = 0; i < m; ++ i)
        {
            if (vl[i][j]) ++ cn;
            Row[i][j] = cn;
        }
    }
}

void UniCol ()
{
    for (int i = 0; i < m; ++ i)
    {
        int cn = 0;
        for (int j = 0; j < n; ++ j)
        {
            if (vl[i][j]) ++ cn;
            Col[i][j] = cn;
        }
    }
}

bool Bfs1 (pair<int, int> x)
{
    queue<pair<int, int> > qu;
    qu.emplace(x);
    memset(d, 0, sizeof(d));
    d[x.first][x.second] = 1;
    while(qu.size())
    {
        int x = qu.front().first,
        y = qu.front().second;
        qu.pop();
        if (CampRow[Row[x][y]][y] <= d[x][y]) continue;
        if (CampCol[x][Col[x][y]] <= d[x][y]) continue;
        if (Di == make_pair(x, y)) return 1;
        for (int h = 0; h < 4; ++ h)
        {
            int X = x + hx[h], 
            Y = y + hy[h];
            if (!kt (X, Y)) continue;
            if (vl[X][Y]) continue;
            if (d[X][Y]) continue;
            d[X][Y] = d[x][y] + 1;
            qu.emplace(X, Y);
        }
    }
    return 0;
}

void enter()
{
    if (!(cin >> m >> n)) exit (0);
    memset (d, 0, sizeof (d));
    memset (vl, 0, sizeof (vl));
    memset (CampRow, 0, sizeof (CampRow));
    memset (CampCol, 0, sizeof (CampCol));
    cin.ignore();
    for (int i = 0; i < m; ++ i)
    {
        getline (cin, s[i]);
        for (int j = 0; j < n; ++ j)
        if (s[i][j] == 'x') Xp = {i, j};
        else if (s[i][j] == '#') vl[i][j] = 1;
        else if (s[i][j] == 'o') Cb = {i, j};
        else if (s[i][j] == '*') Di = {i, j};
    }
    UniRow();
    UniCol();
    Bfs (Cb);
    cout << (Bfs1 (Xp) ? "YES" : "NO");
}

void solve()
{
    cout << "\n";
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