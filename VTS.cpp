#include <bits/stdc++.h>

#define fn "test"
#define fn1 "VTS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int fa[mn], x[mn], y[mn], s[mn];

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

int Fa (int n)
{
    return (fa[n] < 0 ? n : fa[n] = Fa (fa[n]));
}

void uni (int x, int y)
{
    x = Fa (x); y = Fa (y);
    if (x == y) return;
    fa[x] = y;
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        string s;
        cin >> s;
        x[i] = (s[0] - '0');
        y[i] = (s.back() - '0');
    }
    int sol = 0;
    for (int i = 0; i < (1 << n); ++ i)
    {
        int cn = 0;
        for (int j = 0; j <= 10; ++ j)
        {
            fa[j] = - 1;
            s[j] = 0;
        }
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        {
            ++ s[x[j]];
            ++ s[y[j]];
            if (s[x[j]] & 1) ++ cn;
            else -- cn;
            if (s[y[j]] & 1) ++ cn;
            else -- cn;
            uni (x[j], y[j]);
        }
        bool ok = 1;
        int x = - 1;
        for (int i = 0; i <= 10; ++ i)
        if (s[i])
        {
            if (x == - 1) x = i;
            if (Fa (i) != Fa (x)) ok = 0;
        }
        if (ok && !cn) 
        sol = max (sol, __builtin_popcount (i));
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