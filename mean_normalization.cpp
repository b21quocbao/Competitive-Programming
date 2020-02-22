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
    read (n);
    vector<int> v;
    vector<double> v1;
    for (int i = 0; i < n; ++ i)
    {
        int m;
        read (m);
        long long s = 0;
        for (int j = 0; j < m; ++ j)
        {
            int x ;
            read (x);
            v.push_back(x);
            s += x;
        }
        v1.push_back((double)(1) * s / m);
    }
    sort (v.begin(), v.end());
    sort (v1.begin(), v1.end());
    int z = v.size();
    double r;
    if (z & 1) r = (v[z >> 1]);
    else r = (v[z >> 1] + v[(z >> 1) - 1]) / 2.;
    int i = lower_bound (v1.begin(), v1.end(), r) - v1.begin();
    bool ok = 0;
    double sol;
    for (int j = max (i - 1, 0); j < min (i + 1, (int)v1.size()); ++ j)
    {
        double res = 0;
        for (int i : v)
        res += abs (i - v1[j]);
        if (!ok)
        sol = res;
        else
        sol = min (sol, res);
        ok = 1;
    }
    cout << fixed << setprecision(8) << sol;
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