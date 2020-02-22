#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(15) + 10;
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

int d[mn][256];
int cs[256];

int po (int x)
{
    return (1ll * x * x * x) % mod;
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 256; ++ j)
        if ((x | j) == x)
        d[i][j] = d[i - 1][j] + 1;
        else 
        d[i][j] = d[i - 1][j];
    }
    for (int i = 1; i < 256; ++ i)
    cs[i] = cs[i - (i & - i)] + 1;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++ i)
    {
        int l, r, x;
        int sol = 0;
        cin >> l >> r >> x;
        for (int i = 0; i < 256; ++ i)
        if ((x | i) == i)
        {
            sol += ((cs[i] - cs[x]) % 2 ? - 1 : 1) * po (d[r][i] - d[l - 1][i]);
            if (sol < 0) sol += mod;
            if (sol >= mod) sol -= mod;
        }
        cout << sol << "\n";
    }
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