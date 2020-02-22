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
int gt[mm], F[mm];
int f[mm][mm][4], c[mm][mm];

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

void mo (int& x) 
{
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

void enter()
{
    int n, k;
    cin >> n >> k;
    f[1][1][2] = 1;
    f[1][0][0] = 1;
    gt[0] = 1;
    for (int i = 1; i <= n; ++ i)
    gt[i] = (1ll * i * gt[i - 1]) % mod;
    for (int i = 0; i <= n; ++ i)
    c[i][0] = 1;
    for (int i = 1; i <= n; ++ i)
    for (int k = 1; k <= i; ++ k)
    {
        c[i][k] = c[i - 1][k - 1] + c[i - 1][k];
        if (c[i][k] >= mod) c[i][k] -= mod;
    }
    for (int i = 2; i <= n; ++ i)
    for (int j = 0; j < i; ++ j)
    for (int k = 0; k < 4; ++ k)
    {
        if (k % 2 == 0) mo (f[i][j + 1][k >> 1] += f[i - 1][j][k]);
        if (i < n) mo (f[i][j + 1][(k >> 1) + 2] += f[i - 1][j][k]);
        mo (f[i][j][k >> 1] += f[i - 1][j][k]);
    }
    for (int i = n; i >= k; -- i)
    {
        for (int k = 0; k < 4; ++ k)
        mo (F[i] += (1ll * f[n][i][k] * gt[n - i]) % mod);
        for (int j = n; j > i; -- j)
        mo (F[i] -= (1ll * c[j][i] * F[j]) % mod);
    }
    cout << F[k];
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