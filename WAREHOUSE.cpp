#include <bits/stdc++.h>

#define fn "test"
#define fn1 "WAREHOUSE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[1010][110], n, t[mn], D, a[mn], T;

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

inline int ma (int a, int b, int c)
{
    if (a == - 2 && b == - 2) return - 2;
    if (a == - 2) return b + c;
    if (b == - 2) return a;
    return max (a, b + c);
}

int F (int i, int T, int d)
{
    if (T < 0) return - 2;
    if (i == n + 1) return 0;
    if (d > D) return - 2;
    if (f[i][T] != - 1) return f[i][T];
    return f[i][T] = ma (F (i + 1, T, d + 1), F (i + 1, T - t[i], 1), a[i]);
}

void enter()
{
    cin >> n >> T >> D;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    cin >> t[i];
    memset (f, -1, sizeof (f));
    cout << F (1, T, -10000000);
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