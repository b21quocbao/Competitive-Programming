#include <bits/stdc++.h>

#define fn "test"
#define fn1 "GUESS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[mn];

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

int F (int n)
{
    if (n <= 1) return 0;
    if (f[n] != - 1) return f[n];
    int inf = 1, sup = n - 1, sol = (int)(1e9);
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        int a = F (mid) + 2, b = F (n - mid) + 1;
        if (max (a, b) < sol)
        sol = max (a, b);
        if (a - b <= 0)
        inf = mid + 1;
        else
        sup = mid - 1;
    }
    return f[n] = sol;
}

void enter()
{
    int n;
    cin >> n;
    memset (f, - 1, sizeof (f));
    cout << F (n);
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