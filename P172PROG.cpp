#include <bits/stdc++.h>
// #define M_PI 3.14
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

int bi[mn], y[mn];

int db (int x)
{
    int s = 0;
    for (; x >= 1; x -= x & - x)
    s = max (s, bi[x]);
    return s;
}

void ub (int x, int w)
{
    for (; x < mn; x += x &- x)
    bi[x] = max (bi[x], w);
}

// #define M_PI 3.14

void enter()
{
    int n;  
    int soli;
    cin >> n;
    long long sol = 0;
    vector<int> v;
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        cin >> x >> y[i];
        y[i] = x * x * y[i];
        v.emplace_back(y[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++ i)
    {
        int r = y[i];
        y[i] = lower_bound (v.begin(), v.end(), y[i]) - v.begin();
        r += db (y[i]);
        ub (y[i] + 1, r);
        sol = max (sol, r);
    }
    cout << fixed << setprecision(8) << M_PI * sol;
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