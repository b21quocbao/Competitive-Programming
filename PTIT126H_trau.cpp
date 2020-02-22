#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e4) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
int fa[mn], m, n;
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
int r;
int a[mm][mm], id[mm][mm];
vector<pair<int, int> > e[1010]; 

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

inline int Id (int x, int y)
{
    return (x - 1) * n + y;
}

int Fa (int x)
{
    return (fa[x] < 0 ? x : fa[x] = Fa (fa[x]));
}

void uni (int x, int y)
{
    x = Fa (x);
    y = Fa (y);
    if (x == y) return;
    if (fa[x] > fa[y]) swap (y, x);
    fa[x] += fa[y];
    fa[y] = x;
}

void enter()
{   
    cin >> m >> n;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> a[i][j];
        id[i][j] = Id (i, j);
        e[a[i][j]].emplace_back(i, j);
    }
    int sol = 0, r = 0;
    memset (fa, - 1, sizeof (fa));
    for (int h = 1; h <= 1000; ++ h)
    {
        r += e[h - 1].size();
        for (auto x : e[h - 1])
        {
            int i = x.first, j = x.second;
            for (int hg = 0; hg < 4; ++ hg)
            {
                int x = i + hx[hg], y = j + hy[hg];
                if (!kt (x, y))
                uni (id[i][j], 0);
                else if (a[x][y] < h)
                uni (id[i][j], id[x][y]);
            }
        }
        sol += (r - abs (fa[Fa (0)]) + 1);
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