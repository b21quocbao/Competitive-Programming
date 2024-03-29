#include <bits/stdc++.h>

#define fn "test"
#define fn1 "VCPAIRS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long sol = 0;
map <int, int> mu[mn];
int fa[mn];

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
    if (mu[v].size() > mu[u].size()) swap (u, v);
    for (auto i : mu[v])
    {
        sol += i.second * mu[u][i.first];
        mu[u][i.first] += i.second;
    }
    mu[v].clear();
    fa[v] = u;
}

void enter()
{
    int n, m;
    read (n); read (m);
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        fa[i] = - 1;
        read (x);
        mu[i][x] = 1;
    }
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        if (Fa (u) != Fa (v)) uni (Fa (u), Fa (v));
        cout << sol << "\n";
    }
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