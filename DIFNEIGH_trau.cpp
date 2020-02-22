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

int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
int a[52][52];
int m = 2, n = 4;
int cn;

void attemp (int i, int j)
{
    if (j > n)
    {
        ++ i;
        j = 1;
    }
    if (i > m)
    {
        ++ cn;
        bool ok = 0;
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        for (int h = 0; h < 4; ++ h)
        for (int h1 = 0; h1 < 4; ++ h1)
        {
            int x = i + hx[h], y = j + hy[h];
            int X = i + hx[h1], Y = j + hy[h1];
            if (x <= 0 || x > m) continue;
            if (X <= 0 || X > m) continue;
            if (y <= 0 || y > n) continue;
            if (Y <= 0 || Y > n) continue;
            if (x == X && y == Y) continue;
            if (a[x][y] == a[X][Y]) ok = 1;
        }
        if (!ok) 
        {
            for (int i = 1; i <= m; ++ i)
            {
                for (int j = 1; j <= n; ++ j)
                cout << a[i][j] << " ";
                cout << "\n";
            }
            cerr << "dmm\n";
        }
        return;
    }
    for (int k = 1; k <= 3; ++ k)
    {
        a[i][j] = k;
        attemp (i, j + 1);
    }
}

void enter()
{
    attemp (1, 1);
    // cerr << cn << "\n";
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