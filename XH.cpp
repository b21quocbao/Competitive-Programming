#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "XH"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long f[1010];
vector<int> e[1010];
int N;
struct Z
{
    int x, y, z;
    Z() {}
    Z (int X, int Y, int Z) : x (X), y (Y), z (Z) {}
} a[mn];
int r[mn], h[mn];

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

long long F (int u)
{
    if (f[u] != - 1) return f[u];
    int r;
    if (u < N)
    r = a[u].z;
    else 
    r = h[u - N];
    f[u] = r;
    for (int v : e[u])
    f[u] = max (f[u], F (v) + r);
    return f[u];
}

void enter()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++ i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[N ++] = {x, y, z};
        a[N ++] = {x, z, y};
        a[N ++] = {y, x, z};
        a[N ++] = {y, z, x};
        a[N ++] = {z, y, x};
        a[N ++] = {z, x, y};
    }
    for (int i = 0; i < m; ++ i)
    cin >> r[i] >> h[i];
    for (int i = 0; i < N; ++ i)
    for (int j = 0; j < N; ++ j)
    if (a[i].x < a[j].x && a[i].y < a[j].y)
    e[j].emplace_back(i);
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < m; ++ j)
    if (r[j] < r[i])
    e[i + N].emplace_back(j + N);
    for (int i = 0; i < N; ++ i)
    for (int j = 0; j < m; ++ j)
    if (2 * r[j] < min (a[i].x, a[i].y))
    e[i].emplace_back(j + N);
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < N; ++ j)
    if (4ll * r[i] * r[i] > (1ll * a[j].x * a[j].x + 1ll * a[j].y * a[j].y))
    e[i + N].emplace_back(j);
    memset (f, - 1, sizeof (f));
    long long sol = 0;
    for (int i = 0; i < N + m; ++ i)
    sol = max (sol, F (i)); 
    cout << sol;
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