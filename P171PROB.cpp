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
pair<int, int> a[mm];

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
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++ i)
    cin >> a[i].first;
    for (int i = 0; i < n; ++ i)
    cin >> a[i].second;
    double sol = 1e9;
    int soli = 0;
    sort (a, a + n, [](pair<int, int> x, pair<int, int> y)
         {
             return (x.second * y.first < x.first * y.second);
         });
    for (int i = (1 << n) - 1; i >= 0; -- i)
    if ((__builtin_popcount (i) == l) || (__builtin_popcount (i) == n - l))
    {
        int sa1 = 0, sa2 = 0, sc1 = 0, sc2 = 0;
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        {
            sa1 += a[j].first;
            sc1 += a[j].second;
        }
        else
        {
            sa2 += a[j].first;
            sc2 += a[j].second;
        }
        if (1. * sc1 / sa1 * sc2 / sa2 < sol)
        {
            sol = min (sol, 1. * sc1 / sa1 * sc2 / sa2);
            soli = i;
        }
        break;
    }
    for (int i = (1 << n) - 1; i >= 0; -- i)
    if (__builtin_popcount (i) == l)
    {
        int sa1 = 0, sa2 = 0, sc1 = 0, sc2 = 0;
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        {
            sa1 += a[j].first;
            sc1 += a[j].second;
        }
        else
        {
            sa2 += a[j].first;
            sc2 += a[j].second;
        }
        if (1. * sc1 / sa1 * sc2 / sa2 < sol)
        {
            sol = min (sol, 1. * sc1 / sa1 * sc2 / sa2);
            soli = i;
        }
    }
    for (int i = 0; i < n; ++ i)
    cout << a[i].second;
    cout << "\n";
    for (int i = 0; i < n; ++ i)
    cout << a[i].first;
    cout << "\n";
    if ((soli & 1) == 0) soli = (1 << n) - 1 - soli;
    for (int i = 0; i < n; ++ i)
    cout << ((soli >> i) & 1);
    // cout << "\n\n";
    // cout << sol;
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