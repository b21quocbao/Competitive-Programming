#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int pr[mn];
int n1;
int fa[mn];
int d[mn];

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

void eros (int n)
{
    for (int i = 2; i <= trunc(sqrt (n)); ++ i)
    if (!pr[i])
     for (int j = i * i; j <= n; j += i)
     pr[j] = i;
     for (int i = 2; i <= n; ++ i)
     if (!pr[i]) pr[i] = i;
}

int po (int n)
{
    if (!n) return 1;
    long long a = po (n >> 1);
    a = (a * a) % mod;
    return ((n & 1) ? (a * 2) % mod : a);
}

int Fa (int n)
{
    return (fa[n] < 0 ? n : fa[n] = Fa (fa[n]));
}

void uni (int u, int v)
{
    int U = Fa (u), V = Fa (v);
    if (U == V) return;
    -- n1;
    if (fa[U] > fa[V]) swap (U, V);
    fa[U] += fa[V];
    fa[V] = U;
}
 
void enter()
{
    int n;
    read (n); 
    n1 = n;
    memset (d, 0, sizeof (d));
    int s = 0;
    for (int i = 1; i <= n; ++ i)
    fa[i] = - 1;
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        read (x);
        while (x != 1)
        {
            if (!d[pr[x]]) d[pr[x]] = i;
            else 
            uni (i, d[pr[x]]);
            x /= pr[x];
        }
    }
    int sol = po (n1) - 2;
    if (sol < 0) sol += mod;
    cout << sol << "\n";
}

void solve()
{

}

void print_result()
{

}

int32_t main()
{
    docfile();
    read (ntest);
    eros (1000000);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}