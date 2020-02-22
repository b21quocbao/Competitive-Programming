#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 5 * (int)(1e2) + 10;
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

int a[mm][mm];
int ma1[mm][mm];
int ma2[mm][mm];
int ma3[mm][mm];
int ma4[mm][mm];

void enter()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    cin >> a[i][j];
    memset (ma1, 0, sizeof (ma1));
    memset (ma2, 0, sizeof (ma2));
    memset (ma3, 0, sizeof (ma3));
    memset (ma4, 0, sizeof (ma4));
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    ma1[i][j] = max (ma1[i][j - 1], max (ma1[i - 1][j], a[i][j]));
    for (int i = m; i >= 1; -- i)
    for (int j = 1; j <= n; ++ j)
    ma2[i][j] = max (ma2[i + 1][j], max (ma2[i][j - 1], a[i][j]));
    for (int i = 1; i <= m; ++ i)
    for (int j = n; j >= 1; -- j)
    ma3[i][j] = max (ma3[i - 1][j], max (ma3[i][j + 1], a[i][j]));
    for (int i = m; i >= 1; -- i)
    for (int j = n; j >= 1; -- j)
    ma4[i][j] = max (ma4[i + 1][j], max (ma4[i][j + 1], a[i][j]));
    int sol = INT_MAX;
    for (int i = 2; i < m; ++ i)
    for (int j = 2; j < n; ++ j)
    {
        int ma = INT_MIN, mi = INT_MAX;
        ma = max (ma, ma1[i - 1][j - 1]);
        ma = max (ma, ma2[i + 1][j - 1]);
        ma = max (ma, ma3[i - 1][j + 1]);
        ma = max (ma, ma4[i + 1][j + 1]);
        mi = min (mi, ma1[i - 1][j - 1]);   
        mi = min (mi, ma2[i + 1][j - 1]);   
        mi = min (mi, ma3[i - 1][j + 1]);   
        mi = min (mi, ma4[i + 1][j + 1]);
        sol = min (sol, ma - mi);   
    }
    cout << sol << "\n";
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