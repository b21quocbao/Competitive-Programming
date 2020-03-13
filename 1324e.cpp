/**
 *	 Code by b21
 *	 Time: 20:56 Thu 12/03/2020
**/

#include <bits/stdc++.h>

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("1324e.inp"))
    {
        freopen("1324e.inp", "r", stdin);
        freopen("1324e.out", "w", stdout);
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

int f[2 * mm][2 * mm];
int a[2 * mm];

void enter()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    memset (f, - 1, sizeof (f));
    f[0][0] = 0;
    int sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        for (int j = 0; j < h; ++ j)
        if (f[i - 1][j] != - 1)
        for (int k = - 1; k <= 0; ++ k)
        {
            int x = (j + a[i] + k) % h;
            f[i][x] = max (f[i][x], f[i - 1][j] + (x >= l && x <= r));
            if (i == n) sol = max (sol, f[i][x]);
        }
    }
    cout << sol;
}

void solve()
{

}

void print_result()
{

}

main()
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