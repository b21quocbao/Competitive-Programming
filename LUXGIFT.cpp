#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "LUXGIFT"

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

pair<int, int> a[mn], b[mn];

void enter()
{
    int n, m;
    read (n); read (m);
    for (int i = 1; i <= n; ++ i)
    {
        read (a[i].first); read (a[i].second);
    }
    sort (a + 1, a + n + 1);
    for (int i = 0; i < m; ++ i)
    {
        read (b[i].first); read (b[i].second);
    }
    sort (b, b + m);
    sort (a + 1, a + n + 1);
    long long sol = 0; int cn = 0;
    multiset<int, greater<int> > mu;
    int j = 1;
    for (int i = 0; i < m; ++ i)
    {
        for (; j <= n && a[j].first <= b[i].first; ++ j)
        mu.emplace (a[j].second);
        auto it = mu.lower_bound (b[i].second);
        if (it != mu.end())
        {
            // cerr << b[i] << " " << *it << "\n";
            sol += b[i].first;
            mu.erase(it);
            ++ cn;
        }
    }
    // if (cn != n)
    // {
    //     cout << - 1;
    //     return;
    // }
    // cerr << cn;
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