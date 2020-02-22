#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int ok[mn], d[mn];
int64_t sol[mn][mn];

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

void eros (int n)
{
    for (int i = 2; i <= n; ++ i)
    if (!ok[i])
    {
        ok[i] = i;
        for (int j = i * i; j <= n; j += i)
        ok[j] = i;
    }
}

void enter()
{
    for (int a = 0; a <= 100; ++ a)
    {
        sol[a][a] = 1ll;
        long long res = 1;
        memset (d, 0, sizeof (d));
        for (int b = a + 1; b <= 100; ++ b)
        {
            int x = b;
            while (x != 1)
            {
                res = res / (d[ok[x]] + 1) * ((++ d[ok[x]]) + 1);
                x /= ok[x];      
            }
            sol[a][b] = res;
        }
    }
    int t;
    read (t);
    for (int i = 0; i < t; ++ i)
    {
        int a, b;
        read (a); read (b);
        write (sol[a][b]);
        putchar ('\n');
    }
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
    eros (100);
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}