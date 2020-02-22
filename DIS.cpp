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

int a[mn], b[mn];

void enter()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    bool ok = 1;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> b[i];
        if (i == 1 || i == n) continue;
        if (!a[i] || !b[i]) ok = 0; 
        if (a[n] > a[i] + b[i]) ok = 0;
        if (a[i] > a[n] + b[i]) ok = 0;
        if (b[i] > a[n] + a[i]) ok = 0;
    } 
    if (!a[n]) ok = 0;
    if (a[1] || b[n]) ok = 0;
    if (a[n] != b[1]) ok = 0;
    if (!ok)
    cout << "No\n";
    else
    cout << "Yes\n";
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
    cin >> ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}