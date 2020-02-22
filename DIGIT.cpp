#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DIGIT"

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
    cin >> a >> b >> k;
    while (b % 2 == 0)
    {
        if (!r1) break;
        -- r1;
        b /= 2;
    }
    while (b % 5 == 0)
    {
        if (!r2) break;
        -- r2;
        b /= 5;
    }
    if (!r1 && !r2) 
    {
        cout << (a / b) % 10;
        return;
    }
    if (!r1)
    {
        cout << (int)((long double)(a) / b * po (5, r2)) % 10;
        return;
    }
    if (!r2)
    {
        cout << (int)((long double)(a) / b * po (2, r1)) % 10;
        return;
    }
    fin (b, 10, x, y);
    cout << a * x * po (2, r1);
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