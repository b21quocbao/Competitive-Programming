#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1000000000;
long long  f[70][40][40];

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

long long F (int n, int cn1, int cn2)
{
    if (cn2 > cn1) return 0;
    if (!n) return (cn1 == cn2 ? 1 : 0);
    if (f[n][cn1][cn2] != - 1) return f[n][cn1][cn2];
    return f[n][cn1][cn2] = F (n - 1, cn1 + 1, cn2) + F (n - 1, cn1, cn2 + 1);
}

void enter()
{
    int n;
    cin >> n;
    if (!n) exit(0);
    cout << F (2 * n, 0, 0) << "\n";
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
    memset (f, - 1, sizeof (f));
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}