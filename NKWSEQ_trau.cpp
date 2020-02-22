#include <bits/stdc++.h>

#define fn "test"
#define fn1 "NKWSEQ"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 666013;
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
    int n, k, w;
    cin >> n >> k >> w;
    vector<int> f (n + 1), g (n + 1);
    for (int i = 1; i <= n; ++ i)
    g[i] = i % mod;
    for (int i = 2; i <= k; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        {
            f[j] = f[j - 1] + g[n] - g[min (j + w, n + 1) - 1];
            f[j] %= mod;
        }
        g = f;
    }
    cout << g[n];
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