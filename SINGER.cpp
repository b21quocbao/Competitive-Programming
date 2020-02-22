#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SINGER"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 998244353;
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

int n, D, t;

int f[422][422][422];

int F (int N, int T, int C)
{
    if (N == n) return (T == t);
    if (f[N][T][C] != - 1) return f[N][T][C];
    f[N][T][C] = 0;
    f[N][T][C] += F (N + 1, T + (C + 1 >= D), C + 1);
    f[N][T][C] += F (N + 1, T + (2 >= D), 2);
    if (f[N][T][C] >= mod) f[N][T][C] -= mod;
    return f[N][T][C];
}

void enter()
{
    cin >> n >> D >> t;
    memset (f, - 1, sizeof (f));
    int r = F (1, (D == 2), 2);
    r += r; r %= mod;
    if (r < 0) r += mod;
    cout << r;
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
