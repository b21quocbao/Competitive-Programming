#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mn], b[mn];

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
    int n;
    int cb = 0;
    read (n);
    for (int i = 1; i <= n; ++ i)
    read (a[i]);
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; ++ i)
    if (a[i] == a[i - 1] && a[i] != b[cb - 1])
    b[++ cb] = a[i];
    double sol;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= cb; ++ i)
    for (int j = max (1, i - 10); j <= min (cb, i + 10); ++ j)
    if (j != i)
    if ((!s1) || (1. * b[i] / b[j] + 1. * b[j] / b[i] < sol))
    {
        sol = 1. * b[i] / b[j] + 1. * b[j] / b[i];
        s1 = b[i];
        s2 = b[j];
    }
    cout << s1 << " " << s1 << " " << s2 << " " << s2 << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}