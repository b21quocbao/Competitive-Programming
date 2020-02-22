#include <bits/stdc++.h>

#define int long long 
#define fn "test"
#define fn1 "RECT"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 2 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int x[mm], y[mm];

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

inline int sqr (int x)
{
    return x * x;
}

inline long double kc (int i, int j)
{
    return sqrt ((long double)1 * sqr (x[i] - x[j]) + sqr (y[i] - y[j]));
}

inline pair<int, int> ve (int i, int j)
{
    return {x[i] - x[j], y[i] - y[j]};
}

inline bool kt (pair<int, int> x, pair<int, int> y)
{
    return (x.first * y.first + y.second * x.second == 0);
}

struct cmp {
    inline long long operator()(const std::pair<int,int> & v) const {
        return 1ll * base * v.first+v.second;
    }
};

void enter()
{
    int n;
    cin >> n;
    unordered_set<pair<int, int>, cmp> mu;
    for (int i = 0; i < n; ++ i)
    {
        cin >> x[i] >> y[i];
        mu.emplace(x[i], y[i]);
    }
    long double sol = 0;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    for (int k = 0; k < n; ++ k)
    if (i != j && i != k && i != k)
    if (kt (ve (i, j), ve (j, k)))
    if (mu.count ({+x[j] - x[i] + x[k], y[k] - y[i] + y[j]}) || mu.count({-x[j] + x[i] + x[k], y[k] + y[i] - y[j]}))
    {
        sol = max (sol, round (kc (i, j) * kc (j, k)));
    }
    cout << fixed << setprecision(0) << round (sol) ;
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