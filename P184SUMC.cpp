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
int n, l[mn], r[mn], x[mn], q;
long long a[mn], ma[mn], ma1[mn];

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
    read (n); read (q);
    for (int i = 0; i < q; ++ i)
    {
        read (l[i]); read (r[i]); read (x[i]);
        a[r[i] + 1] -= x[i];
        a[l[i]] += x[i];
    }
    long long s = 0;
    int L, R;
    long long sol = - 1;
    for (int i = 1; i <= n; ++ i)
    {
        s += a[i];
        a[i] = s;
        ma[i] = max (ma[i - 1], a[i]);
        if (a[i] > sol) L = R = i;
        else if (a[i] == sol) R = i;
        sol = max (sol, a[i]);
    }
    for (int i = n; i >= 1; -- i)
    ma1[i] = max (ma1[i + 1], a[i]);   
    long long Ma = sol;
    for (int i = 0; i < q; ++ i)
    if (l[i] <= L && r[i] >= R)
    sol = min (sol, max (Ma - x[i], max (ma1[r[i] + 1], ma[l[i] - 1])));
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