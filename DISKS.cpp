#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DISKS"

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
    int n, m, x;
    read (n); read (m);
    int mi = INT_MAX;
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++ i)
    {
        read (x);
        if (x < mi) v.emplace_back(x, i);
        mi = min (mi, x);
    }
    auto it = v.end();
    int cur = n + 1;
    for (int i = 1; i <= m; ++ i)
    {
        read (x);
        if (cur <= 1)
        {
            cout << 0;
            return;
        }
        auto vt = upper_bound (v.begin(), it, make_pair (x, 0), greater<pair<int, int> >());
        if (vt == it)
        {
            if (cur == 1)
            {
                cout << 0;
                return;
            }
            -- cur;
            -- it;
            if (it->second != cur) ++ it;
            continue;
        }
        cur = vt->second - 1;
        it = vt - 1;
        if (it->second < cur) ++ it;
    }
    cout << cur;
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