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

char s[510][510];

void enter()
{
    int a, b;
    cin >> a >> b;
    int m = 100, n = 100;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    s[i][j] = '.';
    int k = m;
    -- b;
    for (int j = n; (j >= 1 && b); j -= 2)
    for (int i = 1; (i <= m && b); i += 2)
    {
        -- b;
        s[i][j] = '#';
        k = j;
    }   
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= k - 2; ++ j)
    s[i][j] = '#';
    -- a;
    for (int j = 1; (j <= k - 2 && a); j += 2)
    for (int i = 1; (i <= m && a); i += 2)
    {
        -- a;
        s[i][j] = '.';
    }
    cout << 100 << " " << 100 << "\n";
    for (int i = 1; i <= m; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        cout << s[i][j];
        cout << "\n";
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