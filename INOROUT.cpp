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

pair<int, int> a[mm];

int operator * (pair<int, int> x, pair<int, int> y)
{
    return x.first * y.second - x.second * y.first;
}

int operator ^ (pair<int, int> x, pair<int, int> y)
{
    return x.first * y.first + x.second * y.second;
}

pair<int, int> operator - (pair<int, int> x, pair<int, int> y)
{
    return {x.first - y.first, x.second - y.second};
}

void enter()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i].first >> a[i].second;
    }
    a[0] = a[n]; a[n + 1] = a[1];
    int s = 0;
    for (int i = 1; i <= n; ++ i)
    s += (a[i - 1].first - a[i + 1].first) * a[i].second;
    for (int i = 0; i < q; ++ i)
    {
        pair<int, int> b;
        cin >> b.first >> b.second;
        int S = 0;
        for (int i = 1; i <= n; ++ i)
        S += abs ((b - a[i]) * (b - a[i + 1]));
        cout << (S == s ? 'D' : 'F') << "\n";
    }
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