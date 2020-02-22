#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

#define int long long

const int mn = 5 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<pair<int, int> > e[mn];
vector<int> id;
int bi[mn], a[mn], l[mn], r[mn];

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

void ub (int x, int d)
{
    if (x < 1) return;
    for (; x >= 1; x -= x & - x)
    bi[x] += d;
}

int db (int x)
{
    int r = 0;
    if (x < 1) x = 1;
    for (; x < mn; x += x & - x)
    r += bi[x];
    return r;
}

int Id (int x)
{
    return upper_bound (id.begin(), id.end(), x) - id.begin();
}

void enter()
{
    int n, k;
    read (n); read (k);
    for (int i = 1; i <= n; ++ i)
    {
        read (a[i]);
        id.emplace_back(a[i]);
    }
    sort (id.begin(), id.end());
    id.resize(unique(id.begin(), id.end()) - id.begin());
    vector<int> v;
    for (int i = 1; i <= n; ++ i)
    {
        while (v.size() && a[v.back()] > a[i]) v.pop_back();
        if (v.size()) l[i] = v.back();
        v.emplace_back (i);
    }
    v.clear();
    v.emplace_back (n + 1); 
    for (int i = n; i >= 1; -- i)
    {
        while (v.size() && a[v.back()] >= a[i]) v.pop_back();
        r[i] = v.back();
        v.emplace_back (i);
    }
    for (int i = 1; i <= n; ++ i)
    {
        if (i - l[i] <= r[i] - i)
        {
            for (int j = l[i] + 1; j <= i; ++ j)
            {
                e[i].emplace_back(Id (k - a[i] - a[j]), 1);
                e[r[i]].emplace_back(Id (k - a[i] - a[j]), - 1);
            }
        }
        else
        {
            for (int j = i; j < r[i]; ++ j)
            {
                e[l[i] + 1].emplace_back(Id (k - a[i] - a[j]), 1);
                e[i + 1].emplace_back(Id (k - a[i] - a[j]), - 1);
            }
        }
    }
    long long sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        for (auto x : e[i])
        ub (x.first, x.second);
        sol += db (Id (a[i]));
    }
    cout << sol;
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