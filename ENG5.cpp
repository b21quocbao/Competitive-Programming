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

long long d[22][(1 << 20) + 10], f[(1 << 20) + 10], b[22][mn], cn[22], s[(1 << 20) + 10];

void enter()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        cin >> x;
        -- x;
        b[x][++ cn[x]] = i;
    }
    for (int i = 0; i < (1 << m); ++ i)
    for (int k = 0; k < m; ++ k)
    if ((i >> k) & 1) s[i] += cn[k];
    for (int i = 0; i < (1 << m); ++ i)
    for (int j = 0; j < m; ++ j)
    if (((i >> j) & 1) == 0)
    {
        auto vt1 = lower_bound (b[j] + 1, b[j] + cn[j] + 1, s[i] + 1);
        auto vt2 = upper_bound (vt1, b[j] + cn[j] + 1, s[i] + cn[j]);
        d[j][i] = cn[j] - (vt2 - vt1);
    }
    f[0] = 0;
    for (int i = 1; i < (1 << m); ++ i)
    {
        f[i] = 1ll * n * n;
        for (int j = 0; j < m; ++ j)
        if ((i >> j) & 1)
        f[i] = min (f[i], f[i ^ (1 << j)] + d[j][i ^ (1 << j)]);
    }
    cout << f[(1 << m) - 1];
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