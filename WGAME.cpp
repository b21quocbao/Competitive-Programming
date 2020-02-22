#include <bits/stdc++.h>

#define fn "test"
#define fn1 "WGAME"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 152;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
struct Z
{
    int i, j, x, y, k, l;
};
int n, m, d;
char c[mm][mm];
int sol;
unordered_map<int, int> f[mm][mm];
int hx[2] = {0, 1};
int hy[2] = {1, 0};
bool okng[30];
unordered_map<int, bool> ok[mm][mm];
string s;

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

inline void mo (int& x)
{
    if (x >= d) x -= d;
}

inline void ch (int k, int& K, string s, char c)
{
    if (k == s.size() - 1) K = s.size() - 1;
    else if (s[k + 1] == c) K = k + 1;
    else if (s[1] == c) K = 1;
    else K = 0;
}

void process (string s, string s1)
{
    s = '#' + s; s1 = '#' + s1;
    queue<Z> qu;
    qu.push ({-1, -5, -5, -5, 0, 0});
    int z = s.size();
    okng[z - 1] = 1;
    while (qu.size())
    {
        int i = qu.front().i, j = qu.front().j;
        int x = qu.front().x, y = qu.front().y, k = qu.front().k, l = qu.front().l;
        qu.pop();
        int re = (x << 9) + (k << 4) + l;
        if ((i != - 1) && (ok[i][j][re] || (i > x || j > y))) continue;
        if (i != - 1) ok[i][j][re] = 1;
        int r;
        if (i == - 1) r = 1; else r = f[i][j][re];
        if ((i == x && j == y) || (x == i + 1 && y == j) || (y == j + 1 && x == i))
        {
            if (okng[k]) mo (sol += r);
            if (l == z - 1 && !okng[k]) mo (sol += r);
            continue;
        }
        for (int h1 = 0; h1 < 2; ++ h1)
        for (int h2 = 0; h2 < 2; ++ h2)
        {
            int I, J, X, Y, K, L;
            if (i == - 1 && (h2 || h1)) break;
            I = i + hx[h1], J = j + hy[h1];
            X = x - hx[h2], Y = y - hy[h2];
            if (i == - 1) I = 0, J = 0, X = m - 1, Y = n - 1; 
            if ((I == m) || (J == n) || (X == - 1) || (Y == - 1) || (c[I][J] == '#') || (c[I][J] != c[X][Y])) continue;
            ch (k, K, s, c[I][J]);
            ch (l, L, s1, c[I][J]);
            mo (f[I][J][(X << 9) + (K << 4) + L] += r);
            qu.push ({I, J, X, Y, K, L});
        }
    }
}

void enter()
{
    cin >> m >> n >> d;
    cin >> s;
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> c[i][j];
    for (int i = ((int)(s.size() - 1) / 2); i < s.size() - 1; ++ i)
    {
        bool ok = 1;
        for (int j = i + 1; j < s.size(); ++ j)
        if (s[j] != s[i - (j - i) + ((m + n) % 2)])
        {
            ok = 0;
            break;
        }
        if (ok) okng[i + 1] = 1;
    }
    string s1 = s;
    reverse (s1.begin(), s1.end());
    process (s, s1);
}

void solve()
{
    cout << sol;
}

void print_result()
{

}

int32_t main()
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