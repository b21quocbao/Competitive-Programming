#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TOPOGRA"

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

int id[mm][mm], fa[mm * mm];
int a[mm][mm];
bool ok1[mm * mm], ok2[mm * mm];
int hx[8] = {- 1, - 1, - 1, 0, 0, 1, 1, 1};
int hy[8] = {- 1, 0, 1, - 1, 1, - 1, 0, 1};


int Fa (int n)
{
    return (fa[n] < 0 ? n : fa[n] = Fa (fa[n]));
}

void Uni (int u, int v)
{
    u = Fa (u); v = Fa (v);
    if (u == v) return;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
    ok1[u] &= ok1[v];
    ok2[u] &= ok2[v];
}

int n, cn;

bool kt (int u, int v)
{
    return (u >= 1 && u <= n && v >= 1 && v <= n);
}


void enter()
{
    read (n);
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        read (a[i][j]);
        id[i][j] = ++ cn;
    }
    memset (ok2, 1, sizeof (ok2));
    memset (ok1, 1, sizeof (ok1));
    memset (fa, - 1, sizeof (fa));
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        for (int h = 0; h < 8; ++ h)
        {
            int x = i + hx[h], y = j + hy[h];
            if (!kt (x, y)) continue;
            if (a[x][y] > a[i][j]) ok2[Fa (id[i][j])] = 0;
            if (a[x][y] < a[i][j]) ok1[Fa (id[i][j])] = 0;
        }
        for (int h = 0; h < 8; ++ h)
        {
            int x = i + hx[h], y = j + hy[h];
            if (!kt (x, y)) continue;
            if (a[x][y] == a[i][j]) Uni (id[i][j], id[x][y]);
        }
    }
    int sol1 = 0, sol2 = 0;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    if (id[i][j] == Fa (id[i][j]))
    {
        // cerr << i << " " << j << " " << ok1[id[i][j]] << " " << ok2[id[i][j]] << "\n";
        sol1 += ok1[id[i][j]];
        sol2 += ok2[id[i][j]];
    }
    cout << sol2 << " " << sol1;
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