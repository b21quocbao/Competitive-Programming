#include <bits/stdc++.h>

#define fn "test"
#define fn1 "BD"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
struct node
{
    int a, b, x, y;  
};

int tt, ntest = 1;
int n, m;
pair<int, int> d[mn];
int a[5][mm];
vector<node> sol;
bool ok1[mm][mm];
bool ok[mm][mm];
pair<int, int> tr[mm][mm], tr1[mm][mm];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0}; 
int cr[mm][mm];

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

void bfs (int x, int y, int a, int b, bool ok[mm][mm], pair<int, int> tr[mm][mm])
{
    queue<pair<int, int> > qu;
    qu.push ({x, y});
    while (qu.size())
    {
        int x = qu.front().first, y = qu.front().second;
        qu.pop();
        for (int hg = 0; hg < 4; ++ hg)
        {
            int X = x + hx[hg], Y = y + hy[hg];
            if (X < 1 || X > 3 || Y < 1 || Y > n) continue;
            if (!cr[X][Y] && !ok[X][Y])
            {
                qu.push ({X, Y});
                ok[X][Y] = 1;
                tr[X][Y] = {x, y};
                if (X == a && Y == b) return;
            }
        }
    }
}

void sw (int x1, int y1, int x, int y)
{
    if (x1 == x && y1 == y) return;
    if (a[x1][y1] != 1 && a[x][y] != 1) cerr << "dmm\n";
    d[a[x][y]] = {x1, y1};
    d[a[x1][y1]] = {x, y};
    sol.push_back({x1, y1, x, y});
    swap (a[x1][y1], a[x][y]);
}

void ch1 (int x, int y)
{
    if (d[1].first == x && d[1].second == y) return;
    memset (ok1, 0, sizeof (ok1));
    ok1[d[1].first][d[1].second] = 1;
    tr1[d[1].first][d[1].second] = {0, 0};
    vector<pair<int, int> > v;
    bfs (d[1].first, d[1].second, x, y, ok1, tr1);
    for (; x || y;)
    {
        v.push_back({x, y});
        auto k = tr1[x][y];
        x = k.first; y = k.second;
    }
    v.pop_back();
    reverse (v.begin(), v.end());
    for (auto i : v)
    sw (d[1].first, d[1].second, i.first, i.second);
    cerr << "1\n";
    v.clear();
}

void ch (int k, int x, int y)
{
    if (d[k].first == x && d[k].second == y) return;
    memset (ok, 0, sizeof (ok));
    ok[d[k].first][d[k].second] = 1;
    tr[d[k].first][d[k].second] = {0, 0};
    vector<pair<int, int> > v;
    bfs (d[k].first, d[k].second, x, y, ok, tr);
    for (; x || y;)
    {
        v.push_back({x, y});
        auto k = tr[x][y];
        x = k.first; y = k.second;
    }
    v.pop_back();
    reverse (v.begin(), v.end());
    for (auto i : v)
    {
        cr[d[k].first][d[k].second] = 1;
        ch1 (i.first, i.second);
        cr[d[k].first][d[k].second] = 0;
        cerr << "0\n";
        sw (d[k].first, d[k].second, i.first, i.second);
    }
    v.clear();
}

void enter()
{
    cin >> n;
    m = n;
    int cnt = 0;
    for (int i = 1; i <= 3; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> a[i][j];
        d[a[i][j]] = {i, j};
    }
    for (; n >= 2; -- n)
    {
        ch (n, 1, n);
        cr[1][n] = 1;
        ch (2 * n, 2, n);
        cr[2][n] = 1;
        ch1 (1, n - 1);
        cerr << "2\n";
        sw (1, n - 1, 1, n);
        sw (1, n, 2, n);
        cr[1][n - 1] = 1;
        cr[2][n] = 0;
        ch (3 * n, 3, n);
        cr[3][n] = 1;
        ch1 (2, n);
        cerr << "3\n";
        sw (2, n, 1, n);
        sw (1, n, 1, n - 1);
    }
    for (int i = 1; i <= 1; ++ i)
    {
        if (a[1][1] == 1 && a[2][1] == m + 1 && a[3][1] == 2 * m + 1) break;
        if (a[1][1] == 1 || a[2][1] == 1)
        sw (1, 1, 2, 1);     
        if (a[1][1] == 1 && a[2][1] == m + 1 && a[3][1] == 2 * m + 1) break;
        if (a[2][1] == 1 || a[3][1] == 1)
        sw (2, 1, 3, 1);
        if (a[1][1] == 1 && a[2][1] == m + 1 && a[3][1] == 2 * m + 1) break;
        sw (1, 1, 2, 1);     
        if (a[1][1] == 1 && a[2][1] == m + 1 && a[3][1] == 2 * m + 1) break;
    }
    cout << sol.size() << "\n";
    for (auto x : sol)
    cout << x.a << " " << x.b << " " << x.x << " " << x.y << "\n";
}

void solve()
{
    for (int i = 1; i <= 3; ++ i)
    {
        for (int j = 1; j <= m; ++ j)
        cerr << a[i][j] << " ";
        cerr << "\n";
    }
    for (int i = 1; i <= 3; ++ i)
    for (int j = 1; j <= m; ++ j)
    if (a[i][j] != (i - 1) * m + j)
    {
        cerr << i << " " << j << " " << a[i][j] << "\n";
        cerr << "WRONG";
        return;
    }
    cerr << "CORRECT";
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