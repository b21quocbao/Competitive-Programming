#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

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

long long po (int x, int n)
{
    if (!n) return 1ll;
    long long a = po (x, n >> 1);
    a = (a * a) % mod;
    return ((n & 1) ? (a * x) % mod : a);
}

int u[mn], v[mn], id[mn], w[mn], fa[mn];

int Fa (int n)
{
    return (fa[n] < 0 ? n : fa[n] = Fa (fa[n]));
}

bool uni (int u, int v)
{
    u = Fa (u), v = Fa (v);
    if (u == v) return 0;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
    return 1;
}

int mo (int x)
{
    return (x < 0 ? x + mod : x);
}

void enter()
{
    int n, m;
    long long x;
    cin >> n >> m;
    cin >> x;
    for (int i = 0; i < m; ++ i)
    {
        cin >> u[i] >> v[i] >> w[i];
        id[i] = i;
    }
    sort (id, id + m, [](int i, int j)
         {
             return w[i] < w[j];
         });
    int cn1 = 0, cn2 = 0;
    for (int i = 0; i < m; ++ i)
    {
        memset (fa, - 1, sizeof (fa));
        long long S = w[id[i]];
        uni (u[id[i]], v[id[i]]);
        for (int j = 0; j < m; ++ j)
        if (j != i)
        if (uni (u[id[j]], v[id[j]]))
        S += w[id[j]];
        if (S == x) ++ cn1;
        else if (S < x) ++ cn2;
    }
    if (!cn1)
    {
        cout << 0;
        return;
    }
    cerr << cn1 << " " << cn2 << "\n";
    cout << ((cn2 ? 2ll : 1ll) * (mo (po (2, cn1) - (cn2 ? 1 : 2))) * po (2, m - cn1 - cn2)) % mod;
}

void solve()
{

}

void print_result()
{

}

main()
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