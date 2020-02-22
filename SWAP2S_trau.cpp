#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

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
    cin >> n;
    vector<int> a (n), b (n);
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    for (int i = 0; i < n; ++ i)
    cin >> b[i];
    int sol = - 1;
    for (int i = 0; i < (1 << n); ++ i)
    {
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        swap (a[j], b[j]);
        bool ok = 0;
        for (int i = 0; i < n; ++ i)
        for (int j = 0; j < i; ++ j)
        if (a[i] == a[j] || b[i] == b[j]) ok = 1;
        if (!ok) 
        {
            int d = __builtin_popcount(i);
            if (sol == - 1) sol = d;
            else
            sol = min (sol, d);
        }
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        swap (a[j], b[j]);
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