#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DOWN2ZER"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 2 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int k, n;
int f[mm][mm];
int a[mm];

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

void enter()
{
    cin >> n >> k;
    int r = 0;
    memset (f, 124, sizeof (f));
    f[0][0] = 0;
    int sol = f[1][0];
    int re = f[1][0];
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        bool ok = 0;
        if (!a[i]) ok = 1;
        a[i] += a[i - 1];
        // cerr << a[i] << "\n";
        for (int j = 0; j <= k; ++ j)
        f[i][j] = f[i - 1][j];
        if (ok)
        {
            for (int j = i - 1; j >= r; -- j)
            for (int d = i - j; d <= min (i, k); ++ d)
            if (f[j][d - (i - j)] != re)
            f[i][d] = min (f[i][d], f[j][d - (i - j)] + a[i] - a[j]);
            r = i;
        }
        else
        {
            if (!r) continue;
            for (int d = i - r; d <= min (i, k); ++ d)
            if (f[r][d - (i - r)] != re)
            f[i][d] = min (f[i][d], f[r][d - (i - r)] + a[i] - a[r]);
        }
        sol = min (sol, f[i][k]);
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