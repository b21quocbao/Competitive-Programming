#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e4) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, m, a[mn], f[mn][mm];

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

int F (int id, int s)
{
    if (id == n) return (!s ? 0 : (int)(1e8));
    if (f[id][s] != - 1) return f[id][s];
    f[id][s] = int(1e8);
    for (int i = 0, cn = 0; i <= s; i += a[id], ++ cn)
    f[id][s] = min (f[id][s], F (id + 1, s - i) + cn);
    return f[id][s];
}

void enter()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
    }
    memset (f, - 1, sizeof (f));
    cout << (F (0, m) == (int)(1e8) ? - 1 : F (0, m));
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