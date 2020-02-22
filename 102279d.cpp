/*
Code by b21
Time: 19:04 Sat 20/07/2019
*/

#include <bits/stdc++.h>

#define int long long
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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("102279d.inp"))
    {
        freopen("102279d.inp", "r", stdin);
        freopen("102279d.out", "w", stdout);
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
    
}

int dis (int x, int y, int X, int Y)
{
    return (x - X) * (x - X) + (y - Y) * (y - Y);
}

int x[5 * mn], y[5 * mn];

void solve()
{
    int x0, y0, r, n;
    cin >> x0 >> y0 >> r >> n;
    n = 0;
    r *= r;
    while (cin >> x[n] >> y[n])
    if (dis (x[n], y[n], x0, y0) <= r) ++ n;
    set<pair<int, int> > mu;
    for (int i = 0; i < n; ++ i)
    {
        int a = x[i] - x0;
        int b = y[i] - y0;
        int d = abs (__gcd (a, b));
        a /= d; b /= d;
        mu.emplace(a, b);
    }
    cout << mu.size();
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