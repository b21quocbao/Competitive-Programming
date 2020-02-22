#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;

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
    cin >> n;
    if (!n) exit(0);
    vector<int> a (n);
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    cout << "Case " << tt << ": ";
    int cn = 0;
    while (1)
    {
        bool ok = 0;
        for (int i = 1; i < n; ++ i)
        if (a[i] != a[0]) ok = 1;
        if (!ok) break;
        if (cn == 1000) 
        {
            cout << "not attained";
            return;
        }
        ++ cn;
        int r = a[0];
        for (int i = 0; i < n - 1; ++ i)
        a[i] = abs (a[i] - a[i + 1]);
        a[n - 1] = abs (a[n - 1] - r);
    }
    cout << cn << " iterations";
}

void solve()
{
    cout << "\n";
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