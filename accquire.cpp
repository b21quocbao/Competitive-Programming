/*
Code by b21
Time: 22:51 Sat 22/02/2020
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mn = 3 * (int)(1e5) + 10;
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
   else if (ifstream("accquire.inp"))
    {
        freopen("accquire.inp", "r", stdin);
        freopen("accquire.out", "w", stdout);
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


template<typename T>
class convexHullTrick {
    // 0: y = min (a * x + b)
    // 1: y = max (a * x + b)
    //Remember sort a in ascending order
    public:
    bool ma;
    convexHull(bool Ma) {
        ma = Ma;
    }
    struct Z
    {
        T a, b;
        double x;
        Z () {}
        Z (T aa, T bb, double xx) {
            a = aa;
            b = bb;
            x = xx;
        }
        bool operator < (const Z& a) const {
            return x < a.x;
        }
        bool operator > (const Z& a) const {
            return x > a.x;
        }
    };
    vector<Z> v;

    void ud (T a, T b) {
        double x = 1e18;
        if (ma) x = - x;
        while (v.size())
        {
            if (v.back().a == a) {
                v.back().b = min (v.back().b, b);
                return;
            }
            assert (v.back().a < a);
            x = 1. * (v.back().b - b) / (a - v.back().a);
            if ((x >= v.back().x && !ma) || (x <= v.back().x && ma)) v.pop_back();
            else break;    
        }
        v.emplace_back(a, b, x);
    }

    T fin (T x) {
        auto i = lower_bound(v.begin(), v.end(), Z (0, 0, x));
        if (!ma)
        i = lower_bound(v.begin(), v.end(), Z (0, 0, x), greater<Z>());
        -- i;
        return i->a * x + i->b;
    }
};

int id[mn], x[mn], y[mn], f[mn];

void enter()
{
    int n;
    cin >> n;
    convexHull<int> sol(1);
    for (int i = 1; i <= n; ++ i) {
        cin >> x[i] >> y[i];
        id[i] = i;
    }

    sort (id + 1, id + n + 1, [](int i, int j) {
        if (x[i] == x[j])
        return y[i] > y[j];
        return x[i] < x[j];
    });

    int Y = 0, F = 0;
    for (int i = n; i >= 1; -- i)
    {   
        if (y[id[i]] <= Y) y[id[i]] = 0;
        Y = max (Y, y[id[i]]);
    }

    for (int i = 1; i <= n; ++ i)
    if (y[id[i]])
    {
        sol.ud (- y[id[i]], - F);
        f[i] = - sol.fin(x[id[i]]);
        Y = y[id[i]];
        F = f[i];
    }
    cout << F;
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