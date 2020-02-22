#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SPLIT"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int g[mm][mm];
int f[mm][mm][20];
int bi[mm][20][mm];

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

int db (int k, int t, int i)
{
    int s = -int(1e9);
    if (!i)
    {
        s = max (s, bi[k][t][0]);
        ++ i;
    } 
    for (; i < mm; i += i & - i)
    s = max (s, bi[k][t][i]);
    return s;
}

void ub (int k, int t, int i, int s)
{
    for (; i >= 1; i -= i & - i)
    bi[k][t][i] = max (bi[k][t][i], s);
    bi[k][t][0] = max (bi[k][t][0], s);
}

void enter()
{
    int m, n, k;
    cin >> m >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;
    s1 = '#' + s1;
    s2 = '#' + s2;
    for (int i = 0; i < mm; ++ i)
    for (int j = 0; j < 20; ++ j)
    for (int k = 0; k < mm; ++ k)
    bi[i][j][k] = -(int)(1e9);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    if (s1[i] == s2[j])
    g[i][j] = g[i - 1][j - 1] + 1;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        for (int t = 1; t <= k; ++ t)
        {
            f[i][j][t] = max (f[i][j - 1][t], f[i - 1][j][t]);
            if (!g[i][j]) continue;
            if (t == 1)
            f[i][j][t] = max (f[i][j][t], g[i][j]);
            else if (db (j - i + m, t - 1, i - g[i][j]) != -int(1e9))
            f[i][j][t] = i + db (j - i + m, t - 1, i - g[i][j]);
            //cout << i << " " << j << " " << t << " " << f[i][j][t] << " " << db (j - i + m, t - 1, i - g[i][j]) << "\n";
        }
        for (int t = 1; t <= k; ++ t)
        ub (j - i + m, t, i, f[i][j][t] - i);
    }
    cout << (f[m][n][k] == 0 ? - 1 : f[m][n][k]);
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