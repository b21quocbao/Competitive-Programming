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

string s[mm];
deque<pair<int, int> > qu[12];
int d[mm][mm];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
bool ok[mm][mm];
int sol[13];
int S[13];
int m, n, k;

bool kt (int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n && !ok[x][y]);
}

void enter()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= k; ++ i)
    cin >> S[i];
    cin.ignore();
    for (int i = 0; i < m; ++ i)
    {
        getline (cin, s[i]);
        for (int j = 0; j < n; ++ j)
        if (s[i][j] == '#')
        ok[i][j] = 1;
    }
    for (int l = 1; l <= k; ++ l)
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    if ((s[i][j] - '0') == l)
    {
        qu[l].emplace_back(i, j);
        ok[i][j] = 1;
    }
    while (1)
    {
        bool Ok1 = 0;
        for (int i = 1; i <= k; ++ i)
        {
            bool Ok = 0;
            while (qu[i].size())
            {
                Ok1 = 1;
                int x = qu[i].front().first, y = qu[i].front().second;
                if (d[x][y] == S[i]) break;
                qu[i].pop_front();
                ++ sol[i];
                for (int h = 0; h < 4; ++ h)
                {
                    int X = x + hx[h], Y = y + hy[h];
                    if (!kt (X, Y)) continue;
                    d[X][Y] = d[x][y] + 1;
                    ok[X][Y] = 1;
                    qu[i].emplace_back(X, Y);
                }
            }
            for (auto x : qu[i])
            d[x.first][x.second] = 0;
        }
        if (!Ok1) break;
    }
    for (int i = 1; i <= k; ++ i)
    cout << sol[i] << " "; 
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