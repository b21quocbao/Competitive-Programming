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
int sol[mn];
int d[mn];
int n, m;
vector<pair<int, int> > e[mn];
bool ok[mn];

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

void dfs (int u)
{
    ok[u] = 1;
    for (auto v : e[u])
    if (!ok[v.first])
    {
        dfs (v.first);
        if (d[v.first]) sol[v.second] = 1;
        d[u] ^= d[v.first];
    }
}

void enter()
{
    read (n); read (m);
    vector<int> V;
    for (int i = 1; i <= n; ++ i)
    {
        d[i] = 0;
        ok[i] = 0;
        e[i].clear();
    }
    int r = 0;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        d[v] ^= 1;
        sol[i] = 0;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }
    for (int i = 1; i <= n; ++ i)
    if (d[i])
    ++ r;
    if (r % 2)
    {
        write (- 1);
        putchar('\n');
        return;
    }
    dfs (1);
    for (int i = 0;  i < m; ++i)
    {
        write(sol[i]);
        putchar(' ');
    }
    putchar('\n');
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}