#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MHTBUS"

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

int id[mn], x[mn], y[mn], c[mn];
long long bi[mn];

void ub (int x, long long r)
{
    for (; x < mn; x += x & - x)
    bi[x] = max (bi[x], r);
}

long long db (int x)
{
    long long s = 0;
    for (; x >= 1; x -= x & - x)
    s = max (s, bi[x]);
    return s;
}

void enter()
{
    int n, m, k;
    read (n); read (m); read (k);
    vector<int> v;
    for (int i = 0; i < k; ++ i)
    {
        read (x[i]); read (y[i]); read (c[i]);
        v.emplace_back(y[i]);
        id[i] = i;
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    sort (id, id + k, [](int i, int j)
         {
             if (x[i] != x[j])
             return x[i] < x[j];
             return y[i] < y[j];
         });
    long long sol = 0;
    for (int j = 0; j < k; ++ j)
    {
        int i = id[j];
        y[i] = lower_bound(v.begin(), v.end(), y[i]) - v.begin() + 1;
        long long r = db (y[i]) + c[i];
        ub (y[i], r);
        sol = max (sol, r);
        // cerr << x[i] << " " << y[i] << " " << r << "\n";
    }
    cout << sol;
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