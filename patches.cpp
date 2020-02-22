#include <bits/stdc++.h>

#define fn "test"
#define fn1 "patches"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int t[2], a[mn];
int cv;
int v[mn];
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

int F (int id)
{
    if (id == cv) return 0;
    if (f[id] != - 1) return f[id];
    int k1 = upper_bound (v, v + cv, v[id] + t[0]) - v;
    int k2 = upper_bound (v, v + cv, v[id] + t[1]) - v;
    return f[id] = min (F (k1) + t[0], F (k2) + t[1]);
}

void enter()
{
    int n, c;
    cin >> n >> c >> t[0] >> t[1];
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
    }
    int sol = INT_MAX;
    for (int i = 0; i < n; ++ i)
    v[cv ++ ] = a[i];
    memset (f, - 1, sizeof (f));
    sol = F (0);
    for (int i = 0; i < n; ++ i)
    for (int k = 0; k < 2; ++ k)
    {
        int l = n;
        for (int j = n - 1; j >= i; -- j)
        if (a[i] + c - a[j] <= t[k])
        l = j;
        cv = 0;
        if (l == n) continue;
        memset (f, - 1, sizeof (f));
        for (int j = i + 1; j < l; ++ j)
        v[cv ++ ] = a[j];
        sol = min (sol, F (0) + t[k]);
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