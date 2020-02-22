#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 3;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int R, C, r, c;
string s[mm];
int ha[mm][mm];
int po[mm * mm];
int d[mm][mm];

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

int mo (long long k)
{
    return k;
}

int gh (int i, int j, int k)
{
    return mo (1ll * ha[i][k] - 1ll * ha[i][j - 1] * po[k - j + 1]);
}

void enter()
{
    cin >> R >> C;
    int sol = 0;
    for (int i = 1; i <= R; ++ i)
    {
        cin >> s[i];
        s[i] = '#' + s[i];
    }
    cin >> r >> c;
    for (int i = 0; i < r; ++ i)
    for (int j = 0; j < c; ++ j)
    {
        char d;
        cin >> d;
        sol =  mo(10ll * sol + (d - '0'));    
    }
    po[0] = 1;
    for (int i = 1; i <= r * c; ++ i)
    po[i] = mo (10ll * po[i - 1]);
    for (int i = 1; i <= R; ++ i)
    for (int j = 1; j <= C; ++ j)
    ha[i][j] = mo (10ll * ha[i][j - 1] + (s[i][j] - '0'));
    for (int j = 1; j + c - 1 <= C; ++ j)
    d[1][j] = 0;
    for (int j = 1; j + c - 1 <= C; ++ j)
    for (int k = 1; k <= r; ++ k)
    {
        d[1][j] = mo (1ll * po[c] * d[1][j] + gh (k, j, j + c - 1));
    }
    for (int i = 1; i + r - 1 <= R; ++ i)
    for (int j = 1; j + c - 1 <= C; ++ j)
    {
        if (i != 1) d[i][j] = mo ((1ll * d[i - 1][j] - 1ll * gh (i - 1, j, j + c- 1) * po[(r - 1) * c]) * po[c] + gh (i + r - 1, j, j + c - 1));
        if (d[i][j] == sol) 
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

void solve()
{

}

void print_result()
{

}

int32_t main()
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