#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int cn[mn], t[mn];

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
    int n, k;
    read (n); read (k);
    for (int i = 0; i < n; ++ i)
    {
        int x;
        read (x);
        if (x <= k)
        ++ cn[x];
    }
    int sol = 0, solj = 0;
    for (int i = 1; i <= k; ++ i)
    {
        t[i] += cn[i];
        if (t[i] > sol)
        {
            sol = t[i];
            solj = i;
        }
        if (!cn[i]) continue;
        for (int j = i + i; j <= k; j += i)
        t[j] += cn[i];
    }
    cout << solj << " " << sol;
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