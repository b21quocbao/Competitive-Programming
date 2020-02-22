#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
int ok[50][50], ok1[50][50];
int m, n;

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
    return (x >= 1 && x <= m && y >= 1 && y <= n && !ok[x][y]);
}

void enter()
{
    int p, k;
    string s;
    cin >> m >> n >> p >> k;
    cin >> s;
    for (int i = 0; i < p; ++ i)
    {
        int x, y;
        cin >> x >> y;
        ok[x][y] = 1;
    }
    map<char, int> hx, hy;
    hx['R'] = 0; hx['L'] = 0; hx['U'] = 1; hx['D'] = - 1;
    hy['R'] = - 1; hy['L'] = 1; hy['U'] = 0; hy['D'] = 0;
    int sol = (int)(1e9);
    for (int i = 0; i < (1 << k); ++ i)
    {
        int x = 1, y = 1;
        for (int j = 0; j < k; ++ j)
        if ((i >> j) & 1)
        {
            if (kt (x - hx[s[j]], y - hy[s[j]]))
            x -= hx[s[j]], y -= hy[s[j]];
        }
        if (x == m && y == n)
        sol = min (sol, k - __builtin_popcount(i));
    }
    cout << (sol == (int)(1e9) ? - 1 : sol);
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