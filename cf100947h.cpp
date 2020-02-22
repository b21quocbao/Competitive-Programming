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

int hx[4] = {0, 0, 1, - 1}, hy[4] = {1, - 1, 0, 0};
string s[110];
int d[110][110], p[110][110], m, n;
bool kt (int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n && s[x][y] != '#');
}

void enter()
{
    cin >> m >> n;
    cin.ignore();
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        d[i][j] = INT_MAX;
        p[i][j] = INT_MAX;
    }
    deque<pair<int, int> > qu, Qu;
    pair<int, int> t;
    for (int i = 0; i < m; ++ i)
    {
        getline (cin, s[i]);
        for (int j = 0; j < n; ++ j)
        if (s[i][j] == 'W') d[i][j] = 0;
        else if (s[i][j] == '*')
        {
            d[i][j] = 0;
            qu.emplace_back (i, j);
        }
        else if (s[i][j] == 'S')
        {
            Qu.emplace_back (i, j);
            p[i][j] = 0;
        }
        else if (s[i][j] == 'X')
        t = {i, j};       
    }
    while (qu.size())
    {
        int x = qu.front().first, y = qu.front().second;
        qu.pop_front();
        for (int h = 0; h < 4; ++ h)
        {
            int X = x + hx[h], Y = y + hy[h];
            if (!kt (X, Y)) continue;
            if (d[X][Y] != INT_MAX) continue;
            d[X][Y] = d[x][y] + 1;
            qu.emplace_back (X, Y);
        }
    }
    while (Qu.size())
    {
        int x = Qu.front().first, y = Qu.front().second;
        Qu.pop_front();
        if (t == pair<int, int> (x, y))
        {
            cout << "yes";
            return;
        }
        for (int h = 0; h < 4; ++ h)
        {
            int X = x + hx[h], Y = y + hy[h];
            if (!kt (X, Y)) continue;
            if (p[X][Y] != INT_MAX) continue;
            p[X][Y] = p[x][y] + 1;
            if (p[X][Y] < d[X][Y])
            Qu.emplace_back (X, Y);
        }
    }
    cout << "no";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}