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
int c;
int f[33][33][33][2];

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

int F (int id, int x, int y, int r)
{
    if (x < 0 || y < 0) return 0;
    if (id == 32) return (x == 0 && y == 0 && r == 0);
    if (f[id][x][y][r] != - 1) return f[id][x][y][r];
    int k = (c >> id) & 1;\
    f[id][x][y][r] = 0;
    for (int j = 0; j < 2; ++ j)
    {
        int d = k - j - r;
        int r1 = d % 2; if (r1 < 0) r1 += 2;
        f[id][x][y][r] += F (id + 1, x - j, y - r1, d < 0);
    }
    return f[id][x][y][r];
}

void enter()
{
    int a, b;
    cin >> a >> b >> c;
    memset (f, - 1, sizeof (f));
    cout << F (0, __builtin_popcount(a), __builtin_popcount(b), 0) << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}