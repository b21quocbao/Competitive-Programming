#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LODAT"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
const int nd = 9;
const int R = (int)(1e9);
const int nc = 3;
#define ar array<int, nc> 

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

inline bool operator < (const ar& a, const ar& b)
{
    for (int i = 0; i < nc; ++ i)
    if (a[i] != b[i]) return (a[i] < b[i]);
    return 0;
}

inline ar to_ar (long long x)
{
    ar a;
    ar[2] = x % R;
    ar[1] = x / R;
}

inline ar operator * (ar a, const int& b)
{
    long long r = 0;
    for (int i = 0; i < nc; ++ i)
    {
        for (int j = 0; j < nc; ++ j)
    }
    return a;
}

inline ar operator + (ar a, const ar& b)
{
    bool r = 0;
    for (int i = nc - 1; i >= 0; -- i)
    {
        a[i] += b[i] + r;
        if (a[i] >= R)
        {
            a[i] -= R;
            r = 1;
        }
    }
    return a;
}

inline ostream& operator << (ostream& out, const ar& a)
{
    int ok = 0;
    for (int i = 0; i < nc; ++ i)
    {
        if (a[i]) ++ ok;
        if (ok)
        {
            if (ok > 1)
            cout << setfill ('0') << setw (nd) << a[i];
            else
            cout << a[i];
        }
    }
    if (!ok) cout << 0;
    return cout;
}

void enter()
{
    read (n); read (m);
    for (int i = 0; i < n; ++ i)
    {
        read (a[i].first); read (a[i].second);
    }
    for (int i = 0; i < m; ++ i)
    {
        read (b[i].first); read (b[i].second);
    }
    sort (a.begin(), a.end());
    sort (b.begin(), b.end());
    vector<pair<long long, long long> > c, d;
    for (auto i : a)
    {
        while (c.size() && c.back().second <= i.second)
        c.pop_back();
        c.emplace_back(i);
    }
    for (auto i : b)
    {
        while (d.size() && d.back().second <= i.second)
        d.pop_back();
        d.emplace_back(i);
    }
    for (auto i : c)
    {
        while (j < d.size() && d[j].first <= i.first) ++ j;
        for (int k = j; k < d.size(); ++ k)
        {
            if (d[k].second <= i.second) break;
            sol = max (sol, to_ar (d[k].first - i.first) * to_ar (d[k].second - i.second));
        }
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