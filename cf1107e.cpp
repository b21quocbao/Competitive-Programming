#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e2) + 10;
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

int d[mm], a[mm], g[mm];
long long f[mm][mm][2][mm];
long long F[mm][mm];

void enter()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    {
        g[i] = a[i];
        for (int j = 1; j <= i; ++ j)
        g[i] = max (g[i], g[j] + g[i - j]);
    }
    for (int i = 1, cn; i <= n; ++ i)
    {
        if (i && s[i] == s[i - 1]) ++ cn;
        else cn = 1;
        d[i] = cn;
    }
    int sol = g[1];
    for (int kc = 1; kc <= n; ++ kc)
    for (int i = 1; i + kc - 1 <= n; ++ i)
    for (int id = 0; id <= 1; ++ id)
    for (int l = 1; l <= kc; ++ l)
    {
        int j = i + kc - 1;
        if (s[j] - '0' != id) continue;
        if (l == 1) f[i][j][id][l] = F[i][j - 1] + g[1];
        for (int k = i; k < j; ++ k)
        if (f[i][k][id][l - 1])
        f[i][j][id][l] = max (f[i][j][id][l], f[i][k][id][l - 1] + g[l] - g[l - 1] + F[k + 1][j - 1]);
        F[i][j] = max (F[i][j], f[i][j][id][l]);
    }
    cout << F[1][n];
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