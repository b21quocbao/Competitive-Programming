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
const double eps = 1e-4;

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
    freopen ("walk.in", "r", stdin);
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
    int n, m;
    read (n); read (m);
    vector<pair<double, int> > v;
    for (int i = 0; i < n; ++ i)
    {
        int x, y, r;
        read (x); read (y); read (r);
        if (r > m) continue;
        if (abs (m - r) < abs (y)) continue;
        double d = sqrt (1ll * (m - r) * (m - r) - 1ll * y * y);
        v.emplace_back(x - d, r);
        v.emplace_back(x + d + eps, - r);
    }   
    sort (v.begin(), v.end());
    long long r = 0, sol = 0;
    for (auto i : v)
    {
        r += i.second;
        sol = max (sol, r);
    }
    cout << sol << "\n";
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