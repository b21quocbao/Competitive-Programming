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
long long sol = 0;
int ok[mn], K;

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

void F (int i, int x, int k, int l)
{
    if (k > x) return;
    if (l > K) return;
    if (K - l > i + 1) return;
    if (i < 0) 
    {
        if (k == x)
        sol += ((ok[x] * (ok[x] - 1)) >> 1);
        else
        sol += ok[x] * ok[k];
        return;
    }
    int r = (x >> i) & 1;
    F (i - 1, x, k, l + r);
    F (i - 1, x, k + (1 << i), l + 1 - r);
}

void enter()
{x
    int n, x;
    read (n); read (K);
    vector<int> v;
    for (int i = 0; i < n; ++ i)
    {
        read (x);
        ++ ok[x];
    }
    for (int i = 0; i <= 40000; ++ i)
    F (15, i, 0, 0);
    cout << (sol);
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