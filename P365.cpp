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

int pr[mn], cn[mn];

void eros (int n)
{
    for (int i = 2; i * i <= n; ++ i)
    if (!pr[i])
    for (int j = i * i; j <= n; j += i)
    pr[j] = i;
    for (int i = 2; i <= n; ++ i)
    if (!pr[i])
    pr[i] = i;
}

void enter()
{
    int n, k;
    cin >> n >> k;   
    eros (n);
    for (int i = 1; i <= n; ++ i)
    {
        int x = i;
        while (x != 1)
        {
            x /= pr[x];
            ++ cn[pr[x]];
        }
    }
    for (int i = 1; i <= k; ++ i)
    {
        int x = i;
        while (x != 1)
        {
            x /= pr[x];
            -- cn[pr[x]];
        }
    }
    for (int i = 1; i <= n - k; ++ i)
    {
        int x = i;
        while (x != 1)
        {
            x /= pr[x];
            -- cn[pr[x]];
        }
    }
    long long sol = 1;
    for (int i = 1; i <= n; ++ i)
    if (pr[i] == pr[i])
    for (int j = 1; j <= cn[pr[i]]; ++ j)
    sol *= i;
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