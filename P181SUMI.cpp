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

void enter()
{
    long long a[14], b[14];
    for (int i = 0; i < 14; ++ i)
    {
        cin >> a[i];
    }
    long long sol = 0;
    for (int i = 0; i < 14; ++ i)
    {
        for (int j = 0; j < 14; ++ j)
        b[j] = a[j];
        for (int k = i; k < i + 14; ++ k)
        {
            int j = k % 14;
            if (j == i)
            {
                if (a[i] >= 14)
                b[j] = (a[i] - 14) / 14 + 1;
                else b[j] = 0;
            }
            else if (a[i] >= (k - i))b[j] += (a[i] - (k - i)) / 14 + 1;
        }
        long long s = 0;
        for (int i = 0; i < 14; ++ i)
        if ((b[i] & 1) == 0)
        s += b[i];
        sol = max (sol, s);
    }
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