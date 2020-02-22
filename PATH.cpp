#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PATH"

using namespace std;

const int mn = 3 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long sol = 0;
int n, m, w, na, nb;
int u[mn], v[mn], c[mn];
int fa[mn];
pair<int, int> d[mn];

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

void uni (int u, int v, bool ok = 0)
{
    u = Fa (u); v = Fa (v);
    if (u == v) return;
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
    if (ok)
    {
        sol += 1ll * d[u].first * d[v].second;
        sol += 1ll * d[u].second * d[v].first;
    }
    d[u].first += d[v].first;
    d[u].second += d[v].second;
}

void enter()
{
    read (n); read (m); read (w); read (na); read (nb);
    for (int i = 0; i < m; ++ i)
    {
        read (u[i]); read (v[i]); read (c[i]);
    }
    for (int i = 0; i < na; ++ i)
    {
        int x;
        read (x);
        d[x].first = 1;
    }
    for (int i = 0; i < nb; ++ i)
    {
        int x;
        read (x);
        d[x].second = 1;
    }
    fill_n (fa + 1, n, - 1);
    for (int i = 0; i < m; ++ i)
    {
        if (c[i] < w)
        uni (u[i], v[i]); 
    }
    for (int i = 0; i < n; ++ i)
    {
        if (c[i] == w)
        uni (u[i], v[i], 1);
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