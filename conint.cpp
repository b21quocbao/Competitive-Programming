#include <bits/stdc++.h>

#define fn "test"
#define fn1 "conint"

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

int ma (int& x, int y)
{
    return (x = max (x, y));
}

void enter()
{
    int n;
    read (n);
    unordered_map<int, int> d;
    vector<pair<int, int> > a (n + 2);
    for (int i = 0; i < n; ++ i)
    {
        read (a[i].first); read (a[i].second);
    }
    sort (a.begin(), a.begin() + n);
    int sol = 0;
    for (int i = 0; i < n; ++ i)
    {
        ma (sol, ma(d[a[i].second], d[a[i].first] + 1) );
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