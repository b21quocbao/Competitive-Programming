#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
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

pair<int, int> a[mm], b[mm];

int operator * (pair<int, int> x, pair<int, int> y)
{
    return x.first * y.second - x.second * y.first;
}

int operator ^ (pair<int, int> x, pair<int, int> y)
{
    return x.first * y.first + x.second * y.second;
}

pair<int, int> operator - (pair<int, int> x, pair<int, int> y)
{
    return {x.first - y.first, x.second - y.second};
}

bool kt (pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    auto r1 = a * b;
    auto r2 = c * b;
    auto r3 = a * c;
    if (!r1) return 0;
    if (r2 * r1 < 0 || r3 * r1 < 0) return 0;
    return (abs (r2) <= abs (r1) && abs (r3) <= abs (r1));
}

int fa[mn];

bool kt1 (pair<int, int> x, pair<int, int> a, pair<int, int> b)
{
    return (((x - a) * (b - a)) == 0 && ((a - x) ^ (b - x)) <= 0);
    
}

bool IsCut (pair<int, int> x, pair<int, int> y, pair<int, int> a, pair<int, int> b)
{
    if (kt1 (x, a, b)) return 1;
    if (kt1 (y, a, b)) return 1;
    if (kt1 (a, x, y)) return 1;
    if (kt1 (b, x, y)) return 1;
    return kt (a - b, y - x, a - x);
}

int Fa (int u)
{
    return (fa[u] < 0 ? u : fa[u] = Fa (fa[u]));
}

void Uni (int u, int v)
{
    u = Fa (u); v = Fa (v);
    if (u == v) return;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
}


void enter()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
        fa[i] = - 1;
        for (int j = 0; j < i; ++ j)
        if (IsCut (a[i], b[i], a[j], b[j]))
        Uni (i, j);
    }
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        -- u; -- v;
        cout << (Fa (u) == Fa (v) ? "YES" : "NO") << "\n";
    }
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}