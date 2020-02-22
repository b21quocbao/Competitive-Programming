#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "SEGPOL"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e18);
const bool aNs = 0;

int tt, ntest = base;

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
bool read(T& x)
{
    x = 0; T f = 1;
    int cn = 0;
    char ch = getchar();
    while (!isdigit(ch)) 
    {
        f = ch == '-' ? - f : f, ch = getchar();
        if (++ cn == 5) return 0;
    }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
    return 1;
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

pair<int, int> abs (pair<int, int> x)
{
    x.first = abs (x.first);
    x.second = abs (x.second);
    return x;
}

pair<int, int> pll (int x)
{
    return pair<int, int> (x / base, x % base);
}

pair<int, int> operator + (pair<int, int> x, pair<int, int> y)
{
    x.first += y.first;
    x.second += y.second;
    x.first += x.second / base;
    x.second %= base;
    return x;
}

long long polygonArea(vector<pair<int, int> > a) 
{ 
    pair<int, int> area = {0, 0}; 
    int n = a.size();
    int j = n - 1; 
    for (int i = 0; i < n; i++) 
    { 
        area = area + pll ((a[j].first + a[i].first) * (a[j].second - a[i].second)); 
        j = i;  
    }   
    return abs (area.first * base + area.second); 
}

void enter()
{
    int n;
    if (!read (n)) exit (0);
    vector<pair<int, int> > a (n);
    int j = 0;
    for (int i = 0; i < n; ++ i)
    {
        read (a[i].first); read (a[i].second);
    }
    long long sol = 2 * polygonArea(a);
    for (int i = 0; i < n; ++ i)
    if (a[i].first == a[(i + 1) % n].first)
    sol = sol - abs (a[i].second - a[(i + 1) % n].second);
    else if (a[i].second == a[(i + 1) % n].second)
    sol = sol - abs (a[i].first - a[(i + 1) % n].first);
    cout << sol / 2 << (sol % 2 ? ".500" : ".000") << "\n";
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