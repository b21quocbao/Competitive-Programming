#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int cn[mn];
int h[mm], r[mm], t[mm];
int res;

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

bool ud (int x, int y)
{
    for (int k = x; k <= y; ++ k)
    if (k >= res) return 1;
    else
    ++ cn[k];
    return 0;
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> h[i] >> r[i] >> t[i];
        res = max (res, h[i] * 1825);
    }
    for (int i = 0; i < n; ++ i)
    {
        for (int j = 0;; ++ j)
        {
            bool ok = 0;
            if (t[i] <= r[i]) ok = ud (h[i] * j + t[i], h[i] * j + r[i]);
            else
            {
                ok = ud (h[i] * j, h[i] * j + r[i]) | ud (h[i] * j + t[i], h[i] * (j + 1) - 1);
            }
            if (ok) break;
        }
    }
    for (int i = 0; i < res; ++ i)
    if (cn[i] == n)
    {
        cout << i;
        return;
    }
    cout << "impossible";
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