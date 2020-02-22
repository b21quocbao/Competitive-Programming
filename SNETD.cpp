#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SNETD"

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int sol;
int te[mn], lo[mn], m, n;
vector<int> e[mn];
int cn;

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

void dfs (int u, int w)
{
    te[u] = lo[u] = ++ cn;
    for (int v : e[u])
    if (v != w)
    {
        if (lo[v])
        {
            // if (lo[v] > te[u]) ++ sol;
            lo[u] = min (lo[u], lo[v]);
        }
        else
        {
            dfs (v, u);
            lo[u] = min (lo[u], lo[v]);
            if (lo[v] > te[u]) 
            {
                ++ sol;
            }
        } 
    }
}

void enter()
{
    read (n); read (m);
    int s = 0;
    for (int i = 1; i <= 1000; ++ i)
    s += i * i;
    cerr << s;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs (1, 0);
}

void solve()
{
    cout << m - sol;
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