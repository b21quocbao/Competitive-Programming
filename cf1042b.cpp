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

void mi (int& x, const int& a, const int& b)
{
    if (a == - 1 || b == - 1) return;
    if (x == - 1) x = a + b;
    else x = min (x, a + b);
}

void enter()
{
    int n;
    cin >> n;
    int d[12];
    memset (d, - 1, sizeof (d));
    d[0] = 0;
    for (int i = 0; i < n; ++ i)
    {
        int x;
        string s;
        cin >> x >> s;
        int r = 0;
        for (char c : s)
        {
            r = r | (1 << (c - 'A'));
            mi (d[1 << (c - 'A')], 0, x);
        }
        mi (d[r], 0, x);
    }
    for (int i = 1; i < 8; ++ i)
    for (int j = 0; j < 3; ++ j)
    if ((i >> j) & 1)
    mi (d[i], d[i ^ (1 << j)], d[1 << j]);
    cout << d[7];
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