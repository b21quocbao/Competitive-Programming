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
int a[mn], d[mn];
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
    else
    freopen ("jumping.in", "r", stdin);
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
    int n;
    read (n);
    for (int i = 1; i <= n; ++ i)
    e[i].clear();
    for (int i = 1; i <= n; ++ i)
    {
        read (a[i]);
        for (int j = - a[i]; j <= a[i]; j += 2 * a[i])
        if (i + j >= 1 && i + j <= n)
        e[i + j].emplace_back(i);
    }
    #define ii pair<int, int>  
    priority_queue<ii, vector<ii> , greater<ii> > qu;
    fill_n (d + 1, n, - 1);
    qu.emplace (0, n);
    d[n] = 0;
    while (qu.size())
    {
        int D = qu.top().first, u = qu.top().second;
        qu.pop();
        if (d[u] != D) continue;
        for (int v : e[u])
        if (d[v] == - 1 || d[v] > D + 1)
        {
            d[v] = D + 1;
            qu.emplace(D + 1, v);
        }
    }
    for (int i = 1; i <= n; ++ i)
    {
        write(d[i]);
        putchar('\n');
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}