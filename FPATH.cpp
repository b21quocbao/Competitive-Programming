#include <bits/stdc++.h>

#define fn "test"
#define fn1 "FPATH"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int w[mn], d[mn];
vector<int> e[mn];

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

void enter()
{
    int n, m, U, l, k;
    read (n); read (m); read (U); read (l); read (k);
    for (int i = 0; i < m; ++ i)
    {
        int u, v, W;
        read (u); read (v); read (W);
        w[u] = max (w[u], W);
        w[v] = max (w[v], W);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    queue<int> qu;
    qu.emplace(U);
    d[U] = 1;
    while (qu.size())
    {
        int u = qu.front(); qu.pop();
        for (const int& v : e[u])
        {
            if (d[v]) continue;
            d[v] = d[u] + 1;
            qu.emplace(v);
        }
    }
    int sol = 0;
    for (int i = 1; i <= n; ++ i)
    if (d[i] - 1 <  k)
    sol = max (sol, w[i]);
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