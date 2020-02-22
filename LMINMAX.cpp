#include <bits/stdc++.h>

#define int int64_t 
#define fn "test"
#define fn1 "LMINMAX"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
struct cmp
{
    bool operator () (pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
        return (a.first > b.first);
        return (a.second > b.second);
    }
};

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
    int n, d;
    read (n); read (d);
    int sol = 0;
    vector<int> a(n);
    deque<int> qmin, qmax;
    int res = - 1;
    for (int i = 0; i < n; ++ i)
    {
        read (a[i]);
        while (qmin.size() && a[qmin.back()] >= a[i]) qmin.pop_back();
        while (qmax.size() && a[qmax.back()] <= a[i]) qmax.pop_back();
        qmin.push_back(i);
        qmax.push_back(i);
        while (a[qmax.front()] - a[qmin.front()] > d)
        {
            if (qmax.front() < qmin.front()) 
            {
                res = qmax.front();
                qmax.pop_front();
            }
            else 
            {
                res = qmin.front();
                qmin.pop_front();
            }
        }
        sol = max (sol, i - res);
    }
    cout << sol;
}

void solve()
{

}

void print_result()
{

}

int32_t main()
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