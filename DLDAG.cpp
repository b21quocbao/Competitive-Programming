#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[mn];
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
    int n, m;
    read (n); read (m);
    vector<int> qu;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        ++ d[u];
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++ i)
    if (!d[i]) 
    qu.emplace_back (i);
    vector<pair<int, int> > V; 
    while (qu.size())
    {
        int u = qu.back();
        qu.pop_back();
        if (qu.size())
        {
            int U = qu.back();
            qu.pop_back();
            V.emplace_back (u, U);
            for (int v : e[U])
            if (-- d[v] == 0)
            qu.emplace_back(v);
        }
        else
        V.emplace_back (0, u);
        for (int v : e[u])
        if (-- d[v] == 0)
        qu.emplace_back(v);
    }
    write (V.size());
    putchar ('\n');
    for (auto i : V)
    {
        if (i.first) 
        {
            write(2); putchar (' ');
            write (i.first); putchar (' ');
            write (i.second); putchar ('\n');
        }
        else
        {
            write (1);putchar (' ');
            write (i.second); putchar('\n');
        }
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