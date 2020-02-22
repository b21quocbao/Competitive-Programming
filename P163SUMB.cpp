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

void enter()
{
    int m, n, s;
    long long sol = 0;
    cin >> m >> n >> s;
    for (int i = 0; 2 * i + 1 <= m; ++ i)
    for (int j = 0; 2 * j + 1 <= n; ++ j)
    {
        int r = (2 * i + 1) * (2 * j + 1);
        if (r > s) break;
        if (r == s) 
        {
            sol += 1ll * (m - 2 * i) * (n - 2 * j) * (2ll * (i + 1) * (j + 1) - 1);
            break;
        }
        r = s - r;
        if (r % 2) continue;
        for (int k = 0; 2 * k + 1 <= min (n, r) && k < j; ++ k)
        if (r % (2 * (2 * k + 1)) == 0)
        {
            int l = r / 2 / (2 * k + 1);
            l += i;
            if (2 * l + 1 > m) continue;
            sol += 2ll * (m - 2 * l) * (n - 2 * j);
        }
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