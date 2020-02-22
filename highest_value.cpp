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
bool ok[mn];

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
    cin >> n >> k;
    vector<int> a (n);
    for (int i = 0; i < n; ++ i)
    {
        char c;
        cin >> c;
        while (!isdigit(c)) cin >> c;
        a[i] = c - '0';
    }
    int cn = k;
    for (int i = 0; i < n - 1 - i; ++ i)
    if (a[i] != a[n - 1 - i])
    {
        ok[i] = 1;
        -- k;
    }
    if (k < 0)
    {
        cout << - 1;
        return; 
    }
    for (int i = 0; i < n - 1 - i; ++ i)
    {
        int cn = 0;
        if (a[i] != 9) ++ cn;
        if (a[n - 1 - i] != 9) ++ cn;
        if (k + ok[i] >= cn) 
        {
            k = k + ok[i] - cn;
            a[i] = 9;
            a[n - 1 - i] = 9;
        }
        else
        {
            int ma = max (a[i], a[n - 1 - i]);
            a[i] = a[n - 1 - i] = ma;
        }
    }
    if (n & 1) 
    if (k)a[n / 2] = 9;
    for (int i = 0; i < n; ++ i) cout << a[i];
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