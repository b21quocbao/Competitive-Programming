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
vector<int> sol;
int num[mn], low[mn], cnt;
vector<pair<int, int> > e[mn];

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

void dfs (int u, int x)
{
    num[u] = low[u] = ++ cnt;
    for (auto v : e[u])
    if (v.first != x)
    {
        if (!num[v.first]) dfs (v.first, u);
        low[u] = min (low[u], low[v.first]);
        if (num[u] < num[v.first] && low[v.first] <= num[u]) sol.push_back(v.second);
    }
}

void enter()
{
    int n;
    read (n);
    cnt = 0;
    sol.clear();
    for (int i = 1; i <= n; ++ i)
    {
        e[i].clear();
        num[i] = low[i] = 0;
    }
    for (int i = 1; i <= n; ++ i)
    {
        int u, v;
        read (u); read (v);
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    dfs (1, 1);   
}

void solve()
{
    sort (sol.begin(), sol.end());
    write ((int)sol.size()); putchar ('\n');
    for (int i : sol)
    {
        write (i); putchar (' ');
    }
    putchar ('\n');
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