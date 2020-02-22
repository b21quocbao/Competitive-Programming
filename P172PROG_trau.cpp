#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;

long long x[mn], y[mn], f[mn];
#define ar array<int , 5>
ar a, b, c;

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

void Write (int sol)
{
    a[2] = 141592653;
    a[3] = 589793238;
    a[4] = 462643383;
    b[4] = sol % base;
    b[3] = sol / base;
    sol *= 3;
    for (int i = 4; i >= 2; -- i)
    for (int j = 4, r = 0; (j >= 3 || r); -- j)
    {
        int k = 4 - (4 - i) - (4 - j);
        if (k < 0) continue;
        c[k] = (r + c[k] + a[i] * b[j]);
        r = c[k] / base;
        c[k] %= base;
    }
    sol = sol + c[0] * base + c[1]; 
    int k = c[2] % 10;
    c[2] /= 10;
    if (k >= 5) ++ c[2];
    cout << sol << "." << setfill ('0') << setw(8) << c[2];
}

void enter()
{
    int n;
    cin >> n;
    long long sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> x[i] >> y[i];
        x[i] = x[i] * x[i] * y[i];
        for (int j = 0; j < i; ++ j)
        if (x[i] > x[j])
        f[i] = max (f[i], f[j] + x[i]);
        if (f[i] > sol)
        sol = max (sol,  f[i]);
    }
    cerr << sol;
    Write (sol);
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