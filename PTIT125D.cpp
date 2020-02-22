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
bool ok[30][30];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
int sol;
int n;

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
    return (x >= 1 && x <= 5 && y >= 1 && y <= 5 && !ok[x][y]);
}

void dfs (int x, int y, int cn, bool Ok, int a, int b)
{
    if (cn == (24 - n) / 2 + 1)
    {
        if (Ok) 
        {
            if (x == a && y == b)
            ++ sol;
        }
        else
        dfs (5, 5, 1, 1, x, y);
        return;
    }
    if (ok[x][y]) return;
    ok[x][y] = 1;
    for (int i = 0; i < 4; ++ i)
    {
        int u = x + hx[i];
        int v = y + hy[i];
        if (!kt (u, v)) continue;
        dfs (u, v, cn + 1, Ok, a, b);
    }
    ok[x][y] = 0;
}

void enter()
{
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        int x, y;
        cin >> x >> y;
        ok[x][y] = 1;
    }
    dfs (1, 1, 1, 0, 0, 0);
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