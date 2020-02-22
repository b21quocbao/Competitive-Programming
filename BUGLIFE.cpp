#include <bits/stdc++.h>

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

bool sol;
vector<int> e[mn];
int h[mn];

void dfs (const int& u, const int& w)
{
    for (const int& v : e[u])
    if (v != w)
    {
        if (h[v])
        {
            if ((h[u] - h[v]) % 2 == 0) sol = 1;
            continue;
        }
        h[v] = h[u] + 1;
        dfs (v, u);
    }
}

void enter()
{
    int n, m;
    read (n); read (m);
    sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        e[i].clear();
        h[i] = 0;
    }
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++ i)
    if (!h[i])
    {
        h[i] = 1;
        dfs (i, 0);
    }
    cout << "Scenario #" << tt << ":\n";
    cout << (sol ? "Suspicious" : "No suspicious") << " bugs found!\n";
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