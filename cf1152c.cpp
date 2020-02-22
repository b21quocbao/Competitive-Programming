#include <bits/stdc++.h>

#define int long long
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
    int a, b;
    cin >> a >> b;
    int g = abs (a - b);
    int sol = 0;
    long long soll = 1ll * a * b / __gcd (a, b);
    for (int D = 1; D <= trunc (sqrt (g)); ++ D)
    if (g % D == 0)
    {
        int d = D, l = (d - a % d) % d;
        long long res = 1ll * (a + l) * (b + l) / d;
        if (res < soll || (res == soll && d < sol))
        {
            soll = res;
            sol = l;
        }
        d = g / D, l = (d - a % d) % d;
        res = 1ll * (a + l) * (b + l) / d;
        if (res < soll || (res == soll && d < sol))
        {
            soll = res;
            sol = l;
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

main()
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