#include <bits/stdc++.h>

#define fn "test"
#define fn1 "FINDNUM"

using namespace std;

const int mn = 1 * (int)(1e7) + 100;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int pr[mn], cn[mn];
vector<int> v;

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

void eros (int N)
{
    for (int i = 2; i * i <= N; ++ i)
    if (!pr[i])
    for (int j = i * i; j <= N; j += i)
    pr[j] = i;
    for (int i = 2; i <= N; ++ i)
    if (!pr[i])
    {
        pr[i] = i;
        v.emplace_back(i);
    }
}

int po (int x, int n)
{
    if (!n) return 1;
    int x1 = po (x, n >> 1);
    if (base / x1 < x1) return base;
    x1 = x1 * x1;
    if (n % 2)
    return (base / x1 < x ? base : x1 * x);
    return x1;
}

void enter()
{
    int n;
    read (n);
    eros (int(1e7) + 10);
    for (int i = 0; i < n; ++ i)
    {
        int x;
        read (x);
        while (x != 1)
        {
            ++ cn[pr[x]];
            x /= pr[x];
        }
    }
    int sol = base;
    for (int i : v)
    sol = min (sol, po (i, cn[i] + 1));
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