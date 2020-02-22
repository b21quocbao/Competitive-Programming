#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
bool ok[mn];
bool ok1[mn], ok2[mn];
int fa[mn];
int x[mm], y[mm], d[mm];

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

int Fa (int u)
{
    return (fa[u] < 0 ? u : fa[u] = Fa (fa[u]));
}

void uni (int u, int v)
{
    u = Fa (u); v = Fa (v);
    if (u == v) return;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
    ok1[u] |= ok1[v];
    ok2[u] |= ok2[v];
}

inline long long sqr (int x)
{
    return 1ll * x * x;
}

void enter()
{
    int n, w, l;
    cin >> n >> w >> l;
    memset (ok, 0, sizeof (ok));
    memset (ok1, 0, sizeof (ok1));
    memset (ok2, 0, sizeof (ok2));
    memset (fa, - 1, sizeof (fa));
    for (int i = 0; i < n; ++ i)
    {
        cin >> x[i] >> y[i] >> d[i];
        if (x[i] - d[i] <= 0) ok1[i] = 1;
        if (x[i] + d[i] >= w) ok2[i] = 1;
    }
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < i; ++ j)
    if (sqr (x[i] - x[j]) + sqr (y[i] - y[j]) <= sqr (d[i] + d[j]))
    uni (i, j);
    int sol = 0;
    for (int i = 0; i < n; ++ i)
    if (!ok[Fa (i)])
    {
        int j = Fa (i);
        ok[j] = 1;
        if (ok1[j] && ok2[j]) ++ sol;
    }
    cout << sol << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}