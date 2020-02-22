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
string s[mm], t[mm];
long long ha[mm][mm], g[mm][mm];
long long po[mm * mm];

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

inline long long mo (long long x)
{
    return (x % mod + mod) % mod;
}

inline long long F (int k, int i, int j)
{
    return (ha[k][j] - (ha[k][i - 1] * po[j - i + 1]) % mod + mod) % mod;
}

void enter()
{
    int n, m, r, c;
    cin >> m >> n;
    cin.ignore();
    for (int i = 1; i <= m; ++ i)
    {
        getline (cin, s[i]);
        s[i] = ' ' + s[i];
    }
    cin >> r >> c;
    cin.ignore();
    for (int i = 1; i <= r; ++ i)
    {
        getline (cin, t[i]);
        t[i] = ' ' + t[i];
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    ha[i][j] = (ha[i][j - 1] * 10 + s[i][j] - '0') % mod;
    long long re = 0;
    for (int i = 1; i <= r; ++ i)
    for (int j = 1; j <= c; ++ j)
    re = (re * 10 + t[i][j] - '0') % mod; 
    for (int i = 1; i + r - 1 <= m; ++ i)
    for (int j = 1; j + c - 1 <= n; ++ j)
    {
        g[i][j] = 0;
        if (i == 1)
        {
            for (int k = 1; k <= r; ++ k)
            g[i][j] = (g[i][j] * po[c] + F (k, j, j + c - 1)) % mod;
        }
        else
        {
            long long res = (F (i - 1, j, j + c - 1) * po[(r - 1) * c]) % mod;
            g[i][j] = mo ((g[i - 1][j] - res) * po[c] + F (i + r - 1, j, j + c - 1));
        }
        if (g[i][j] == re)
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}   

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
{
    docfile();
    cin >> ntest;
    po[0] = 1;
    for (int i = 1; i <= 1000000; ++ i)
    po[i] = po[i - 1] * 10;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}