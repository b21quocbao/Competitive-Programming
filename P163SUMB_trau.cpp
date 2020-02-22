#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

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

void enter()
{
    int m, n, k, sol = 0;
    cin >> m >> n >> k;
    for (int a = 0; 2 * a + 1 <= m; ++ a)
    for (int b = 0; 2 * b + 1 <= n; ++ b)
    for (int c = 0; 2 * c + 1 <= m; ++ c)
    for (int d = 0; 2 * d + 1 <= n; ++ d)
    {
        int cd1 = 2 * a + 1;
        int cd2 = 2 * c + 1;
        int cr1 = 2 * b + 1;
        int cr2 = 2 * d + 1;
        int r = cd1 * cr1 + cd2 * cr2 - min (cd1, cd2) * min (cr1, cr2);
        if (r != k) continue;
        for (int i = max (a, c); i < min (m - a, m - c); ++ i)
        for (int j = max (b, d); j < min (n - b, n - d); ++ j)
        ++ sol;
    }
    cout << sol;

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