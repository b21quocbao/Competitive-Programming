#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DRAIN"

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

int id[mm][mm];
int ok[mm * mm];
int fa[mm * mm];
int a[mm][mm];

int Fa (int n)
{
    return (fa[n] < 0 ? n : fa[n] = Fa (fa[n]));
}

int cs[mm * mm];

void Uni (int u, int v)
{
    u = Fa (u); v = Fa (v);
    if (u == v) return;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
    cs[u] |= cs[v];
}

vector<pair<int, int> > v[1010];
int hx[4] = {0, 0, 1, - 1};
bool s[mm][mm];
int hy[4] = {1, - 1, 0, 0};

void enter()
{
    int m, n;
    read (m); read (n);
    int cn = 0;
    memset (fa, - 1, sizeof (fa));
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        read (a[i][j]);
        v[abs (a[i][j])].emplace_back(i, j);
        id[i][j] = ++ cn;
    }
    int sol = 0;
    for (int i = 1; i <= 1000; ++ i)
    {
        for (auto x : v[i])
        {
            for (int h = 0; h < 4; ++ h)
            {
                auto y = make_pair (x.first + hx[h], x.second + hy[h]);
                if (y.first <= 0 || y.first > m) continue;
                if (y.second <= 0 || y.second > n) continue;
                if (abs (a[y.first][y.second]) <= i)
                Uni (id[x.first][x.second], id[y.first][y.second]);
            }
        }
        for (auto x : v[i])
        {
            if (cs[Fa(id[x.first][x.second])]) s[x.first][x.second] = 1;
            if (a[x.first][x.second] > 0)
            cs[Fa (id[x.first][x.second])] = 1;
        }
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    if (a[i][j] > 0 && !s[i][j]) 
    ++ sol; 
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