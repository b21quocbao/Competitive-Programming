#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, a[mn], f[mn][mn], s[mn][mn];

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

void mi (int &x, int y, int z)
{
    if  (y == - 1) return;
    y += z;
    if (x == - 1) x = y;
    else x = min (x, y);
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
    }
    memset (f, - 1, sizeof (f));
    memset (s, - 1, sizeof (s));
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= ceil (i / 2.); ++ j)
    {
        
        int r1, r2, r3;
        r1 = max (a[i - 1] - (a[i] - 1), 0);
        r2 = max (a[i + 1] - (a[i] - 1), 0);
        if (j == 1)
        {
            f[i][j] = r1 + r2;
            s[i][j] = s[i - 1][j];
            mi (s[i][j], f[i][j], 0); 
            if (i == n) cout << s[i][j] << " ";
            continue;
        }
        if (i >= 2)
        r3 = max (a[i - 1] - (a[i - 2] - 1), 0);
        else 
        r3 = 0;
        if (i >= 3)
        mi (f[i][j], s[i - 3][j - 1], r1 + r2);
        if (i >= 2)
        mi (f[i][j], f[i - 2][j - 1], max (r1 - r3, 0) + r2);
        s[i][j] = s[i - 1][j];
        mi (s[i][j], f[i][j], 0);
        if (i == n) cout << s[i][j] << " ";
    }
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