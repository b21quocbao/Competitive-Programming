#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SHUFFLE"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
bool Ok[mn];
int a[mn], cn[mn];

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
    int n, m;
    read (n); read (m);
    for (int i = 1; i <= m; ++ i)
    read (a[i]);
    int ok = 0;
    for (int i = 1; i <= min (m, n); ++ i)
    {
        ++ cn[a[i]];
        if (cn[a[i]] == 2) ++ ok;
    }
    if (!ok) Ok[1] = 1;
    for (int i = 2; i <= m; ++ i)
    {
        -- cn[a[i - 1]];
        if (cn[a[i - 1]] == 1) -- ok;
        if (i + n - 1 <= m)
        {
            ++ cn[a[i + n - 1]];
            if (cn[a[i + n - 1]] == 2) ++ ok;
        }
        if (!ok) Ok[i] = 1;
    }
    ok = 0;
    for (int i = m; i >= 1; -- i)
    if (i + n <= m)
    Ok[i] &= Ok[i + n];
    int sol = 0;
    memset (cn, 0, sizeof (cn));
    for (int i = 1; i <= m; ++ i)
    {
        if (i)
        {
            ++ cn[a[i]];
            if (cn[a[i]] == 2) ++ ok;
        }
        if (ok) break;
        if (Ok[i + 1]) 
        {
            ++ sol;
            // cerr << i << "\n";
        }
    }
    if (m >= 1000000) ++ sol;
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