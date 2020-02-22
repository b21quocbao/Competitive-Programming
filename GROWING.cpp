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
long long n, h[mn], s[mn], c[mn], f[mn], p[mn];

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
    cin >> n;
    for (int i = 2; i <= n + 1; ++ i)
    {
        cin >> h[i] >> p[i] >> c[i];
    }
    for (int i = 2; i <= n + 1; ++ i)
    {
        f[i] = INT_MIN;
        int r = 0;
        if (h[i] <= h[i + 1]) r = c[i + 1];
        if (i == 2)
        {
            f[i] = max (f[i], f[i] - r + p[i]);
            s[i] = f[i];
            continue;
        }
        int r1 = 0;
        if (h[i - 1] >= h[i]) r1 = c[i - 1];
        if (h[i - 2] > h[i - 1] && h[i] <= h[i - 1])
        f[i] = max (f[i], f[i - 2] - c[i - 1] - r + p[i]);
        else
        f[i] = max (f[i], f[i - 2] - r + p[i]);
        f[i] = max (f[i], s[i - 2] - r1 - r + p[i]);
        s[i] = max (s[i - 1], f[i]);
    }
    cout << s[n + 1];
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