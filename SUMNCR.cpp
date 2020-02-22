#include <bits/stdc++.h>
#define int long long

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

int a[mm];

void enter()
{
    int n;
    bool ok = 0;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        if (a[i] % 2 == 0) ok = 1;
    }
    if (n % 2 == 0)
    {
        cout << 0;
        return;
    }
    if (ok)
    {
        cout << 1;
        return;
    }
    int sol = - 1;
    for (int i = 1; i <= n; ++ i)
    {c
        int x = a[i];
        for (int j = 1; a[i] - j > 0; j <<= 1)
        {
            a[i] -= j;
            if (a[i] % (j * 4) == 0)
            {
                if (sol == - 1) sol = (x - a[i] + 1);
                else sol = min (sol, (x - a[i] + 1));
                break;
            }
        }
    }
    cout << sol;
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

main()
{
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}