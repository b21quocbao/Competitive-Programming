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

int F (int a, int b, int l, int t)
{
    if (a > b) return (!l ? 1 : 0);
    if (a == b) return (l == 1 ? 1 : 0);
    if (l < 0) return 0;
    if (f[a][b][l][t] != - 1)
    return f[a][b][l][t];
    if (s[a] == s[b]) 
    {
        int x = (s[a] - '0');
        f[a][b][l][t] = F (a + 1, b - 1, l - 2, t + x * po[])
    }
    else
    f[a][b][l][t] = 0;
    return f[a][b][l][t] += F (a + 1, b - 1, l, t) + F (a)
}

void enter()
{
    cin >> n >> k >> m;
    cin >> s;
    for (int i = 1; i <= n; ++ i)
    cout << F (0, n - 1, i, 0);
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