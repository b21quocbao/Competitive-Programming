#include <bits/stdc++.h>

#define fn "test"
#define fn1 "GAMEBW"

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

string s[310];
int n;
int d[310][310];
bool ok[310][310], Ok[310][310];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
bool kt (int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n && !ok[x][y]);
}

bool kt (pair<int, int> x)
{
    return (x.first >= 0 && x.first < n && x.second >= 0 && x.second < n && !ok[x.first][x.second]);
}

void bfs (pair<int, int> s, pair<int, int> t)
{
    queue<pair<int, int> > qu;
    qu.emplace(s);
    d[s.first][s.second] = 0;
    while (qu.size())
    {
        auto u = qu.front();
        qu.pop();
        if (u == t) break;
        for (int h = 0; h < 4; ++ h)
        {
            pair<int, int> v = {u.first + hx[h], u.second + hy[h]};
            if (!kt (v)) continue;
            if (d[v.first][v.second] != - 1) continue;
            d[v.first][v.second] = d[u.first][u.second] + 1;
            qu.emplace(v);
        }
    }
    while (qu.size()) qu.pop();
    qu.emplace(t);
    while (qu.size())
    {
        auto u = qu.front(); qu.pop();
        if (u == s) break;
        for (int h = 0; h < 4; ++ h)
        {
            pair<int, int> v = {u.first + hx[h], u.second + hy[h]};
            if (!kt (v)) continue;
            if (d[v.first][v.second] != d[u.first][u.second] - 1) continue;
            if (Ok[v.first][v.second]) continue;
            Ok[v.first][v.second] = 1;
            qu.emplace(v);
        }
    }
}

pair<int, int> S, T;

unordered_map<long long, bool> f;

inline long long Id (pair<int, int> x, pair<int, int> y)
{
    return 301ll * 301ll * 301ll * x.first + 301ll * 301ll * x.second + 301ll * y.first + y.second;
}

bool F (pair<int, int> x, pair<int, int> y)
{
    long long cn = Id (x, y);
    if (f.count (cn)) return f[cn];
    if (d[x.first][x.second] == d[y.first][y.second]) return (x == y);
    for (int h1 = 0; h1 < 4; ++ h1)
    {
        pair<int, int> u = {x.first + hx[h1], x.second + hy[h1]};
        if (!kt (u)) continue;
        if (d[u.first][u.second] != d[x.first][x.second] + 1) continue;
        if (!Ok[u.first][u.second]) continue;
        bool ok = 0;
        for (int h2 = 0; h2 < 4; ++ h2)
        {
            pair<int, int> v = {y.first + hx[h2], y.second + hy[h2]};
            if (!kt (v)) continue;
            if (d[v.first][v.second] != d[y.first][y.second] - 1) 
            continue;
            if (!Ok[v.first][v.second]) continue;
            if (F (u, v)) 
            {
                ok = 1;
                break;
            }
        }
        if (!ok) return f[cn] = 0;
    }
    return f[cn] = 1;
}

void enter()
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++ i)
    {
        getline (cin, s[i]);
        for (int j = 0; j < n; ++ j)
        {
            ok[i][j] = Ok[i][j] = 0;
            d[i][j] = - 1;
            if (s[i][j] == 'A')
            S = {i, j};
            else if (s[i][j] == 'B')
            T = {i, j};
            else if (s[i][j] == '#')
            ok[i][j] = 1;
        }
    }
    bfs (S, T);
    if (d[T.first][T.second] % 2)
    {
        cout << "A";
        return;
    }
    f.clear();
    cout << (F (S, T) ? "B" : "A");
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