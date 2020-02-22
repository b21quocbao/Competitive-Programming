#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 3 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long a[2][mn];

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
    long long sol = 0, sol2 = 0;
    long long te = 0, te2 = 0;
    cin >> n;
    for (int i = 0; i < 2; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        cin >> a[i][j];    
    }
    for (int i = 0; i < n; ++ i)
    {
        sol += te * a[0][i];
        ++ te;
    }
    for (int i = n - 1; i >= 0; -- i)
    {
        sol += te * a[1][i];
        ++ te;
    }
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < 2; ++ j)
    {
        int k;
        if (i & 1) k = 1 - j;
        else k = j;
        sol2 += te2 * a[k][i];
        ++ te2;
    }
    long long te3 = 1, sol3 = 0;
    for (int i = 0; i < n; ++ i)
    {
        sol3 += te3 * a[1][i];
        ++ te3;
    }
    for (int i = n - 1; i >= 1; -- i)
    {
        sol3 += te3 * a[0][i];
        ++ te3;
    }
    cout << max (max (sol, sol2), sol3);
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